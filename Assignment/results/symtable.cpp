/*########################################
      definitions
#########################################*/

#include"symtable.h"
#include <iostream>
using namespace std;

int TOTAL_BIND=0;

/*  structure containing two boxes key (KEY) and value (VALUE)  and next binding (next)*/
struct SymTable_t {
    struct SymTable_t* next;
    // void* KEY;//[100];
    const char *KEY;
    const void*  VALUE;

};
typedef SymTable_t iNode;
// iNode* oSymTable = NULL;

/*  SymTable_new should create a new SymTable structure with no bindings within it.*/
iNode* SymTable_new (){
        TOTAL_BIND++;
        iNode* Newnode = (iNode*)malloc(sizeof(iNode));
        Newnode->next = NULL;
        Newnode->KEY=NULL;
        Newnode->VALUE=NULL;
        return Newnode;
}

/*  free all the memory occupied by the symbol table */
void SymTable_free (SymTable_t *oSymTable){
    struct SymTable_t* tmp = oSymTable;
    while (oSymTable!=NULL)    {
        tmp=oSymTable;
        oSymTable=oSymTable->next;
        free(tmp);
    } 
    TOTAL_BIND=0;    
}

/*  return the total bindings within oSymTable.*/
int SymTable_getLength (SymTable_t *oSymTable){
    return TOTAL_BIND;
}

// inserts returns 1 if pcKey is absent
int SymTable_put (SymTable_t *oSymTable,const char *pcKey, const void *pvValue){
    cout<<"\n**********SymTable_put**********"<<endl;
    int i=0;
    cout<<"pcKey "<<pcKey<<endl;
    cout<<"pvValue "<<*(int*)pvValue<<endl;
    if (oSymTable->KEY==NULL){
        oSymTable->KEY=pcKey;
        // cout<<"KEY ONLY"<<oSymTable->KEY;
        oSymTable->VALUE=pvValue;
        // i++;
        // cout<<"Inserted at oSymTable "<<i<<endl;
        return 1;
    }else if (oSymTable->KEY==pcKey)  {
        return 0;
    }
    // i++;

    // cout<<"2. PUT"<<endl;
    iNode* prev = oSymTable;
    while (prev->next!= NULL && prev->KEY!=NULL){
        i++;
        // cout<<i<<endl;
        if (prev->KEY==pcKey){//key present
            return 0;
        }
        prev = prev->next;
    }
    if (prev->next == NULL) {// create as no memory available
        prev->next=SymTable_new();
    }
    prev->KEY=pcKey;
    prev->VALUE=pvValue;
    // cout<<"KEY ONLY"<<(const char*)prev->KEY;

    // cout<<"Inserted at PREV"<<endl;
    return 1;
}





// searches pcKey. successful, returns the value else NULL
void* SymTable_get (SymTable_t *oSymTable, const char *pcKey){
    iNode* prev = oSymTable;

    // cout<<"\n**********SymTable_get**********"<<endl;
    // int i=0;
    // cout<<"pcKey "<<pcKey<<endl;
    while (prev!= NULL and prev->KEY!=NULL){
        // cout<<"KEY "<<prev->KEY<<endl;
        if (prev->KEY==pcKey){
            // cout<<"VALUE "<<*(int *)prev->VALUE<<endl;
            void *pointer_name;  
            pointer_name=&prev->VALUE;
            return prev;
        }
        prev = prev->next;
    }
    return NULL;
}

// searches pcKey. successful, returns removes the binding else NULL
void *SymTable_remove ( SymTable_t *oSymTable,
                        const char *pcKey){
    iNode* tmp = NULL;
    if (oSymTable->KEY==pcKey){
        tmp=oSymTable;
        oSymTable=oSymTable->next;
        free(tmp);
        return oSymTable;
    }
    iNode* prev = NULL, *NEXT=oSymTable;
    while (NEXT!=NULL &&NEXT->KEY!=NULL)    {
        
        if (NEXT->KEY!=pcKey){
            prev=NEXT;
            NEXT=NEXT->next;
        }else{
            tmp=prev->next;
            prev->next=NEXT->next;
            // free(tmp);
            return tmp;
            // break;
        }
    }   
    // if (NEXT->KEY==NULL)
        return NULL;
    // return prev;
}

// searches to locate pcKey. successful, returns 1 else 0.
int SymTable_contains ( SymTable_t *oSymTable, const char *pcKey){
    // iNode* prev = oSymTable;
    iNode* prev =(iNode*)SymTable_get (oSymTable , pcKey);
    if (prev!=NULL)
        return 1;
    return 0;
}

// searches through oSymTable to locate the binding with pcKey
// if success replace else return NULL
void *SymTable_replace (SymTable_t *oSymTable,
                        const char *pcKey,
                        const void *pvValue){ 
    if (SymTable_contains(oSymTable,pcKey)==0)
        return NULL;
    iNode* prev = oSymTable;
    while (prev!= NULL &&prev->KEY!=NULL){
        if (prev->KEY==pcKey){
            prev->VALUE=pvValue;
            cout<<"REPLACED"<<*(int*)prev->VALUE<<endl;
            return prev;
        }
        prev = prev->next;
    }
    return prev;
}
// printing the SLL
void Print(SymTable_t *oSymTable) {
    int i=0;
    cout << "\n the SLL is " << endl;
    iNode* pre = oSymTable;
    while (pre != NULL && pre->KEY!=NULL){
            int* ptrr1 = (int*)pre->VALUE;
            char* ptrr2 = (char*)pre->KEY;
            const char *c =(char*)pre->KEY;
            cout << "key "<<c << " ->  value "<<*(int*)pre->VALUE<<endl;
            pre = pre->next;

        }
        // cout << pre << "->"<<i<<endl;
        pre = pre->next;
        // i++;
    }

void display(const char *pcKey1, const void *pvValue1){
    cout<<"key = "<<pcKey1<<" with  value = "<<*(int*)pvValue1<<endl;
    
}
// caling another function while traversal
void SymTable_map ( SymTable_t *oSymTable, 
                    void (*pfApply) (const char *pcKey1, const void *pvValue1)){
                    // const char *pcKey,const void *pvValue){   
    iNode* pre = oSymTable;
    int i=0;
    while (pre != NULL and pre->KEY!=NULL) {
        // cout << pre << "->"<<i<<endl;
        pfApply(pre->KEY,pre->VALUE);
        pre = pre->next;
        i++;
    }
}
typedef SymTable_t iNode;





// int main(){
//     int i=2;

//     // create 5 bindings
//     if(oSymTable==NULL){
//         oSymTable=SymTable_new();

//     }
//     iNode* prev= oSymTable;
//     while (i>0)    {
//         prev->next=SymTable_new();
//         prev=prev->next;
//         cout<<i<<endl;
//         i--;
//     }
    
//     cout<<"(SymTable_getLength)Total length including oSymTable is : "<<SymTable_getLength(oSymTable)<<endl;
//     const char *pcKey="i0";
//     // int *pvValue=1;
//     int *x,y=9;
//     x=&y;
//     int result=SymTable_put (oSymTable,pcKey,x);
//     cout<<"(SymTable_put)inserted ..!\nkey : "<<pcKey<<"\nvalue : "<<*x<<endl;
//     Print();
//     // int* ptrr = (int*)oSymTable->VALUE;
//     // char* ptrr = (char*)oSymTable->KEY;
//     // cout<<"*ptrr";

//     int xa=21;
//     x=&xa;
//     string key="i1";
//     const char *pcKey1="i1";

//     // result=SymTable_put (oSymTable,key.c_str(),x);
//     result=SymTable_put (oSymTable,pcKey1,x);

//     Print();

//     const char *pcKey2="i2";
//     // int *pvValue=1;
//     int *x1,y2=19;
//     x1=&y2;
//     result=SymTable_put (oSymTable,pcKey2,x1);
//     Print();

//     cout<<"calling SymTable_get() for KEY = "<<pcKey2<<endl;
//     iNode* prev1 = (iNode*)SymTable_get (oSymTable , pcKey2);
//     if(prev1!=NULL)
//         cout<<"result Value is "<<*(int*)prev1->VALUE<<endl;

//     const char *pcKey5="i5";
//     cout<<"calling SymTable_get() for KEY = "<<pcKey5<<endl;
//     prev1 = (iNode*)SymTable_get (oSymTable , pcKey5);
//     if(prev1!=NULL)
//         cout<<"result Value is "<<prev1->VALUE<<endl;

//     cout<<"calling SymTable_remove() for KEY = "<<pcKey2<<endl;
//     prev1 =(iNode*) SymTable_remove(oSymTable,pcKey2);
//     if(prev1!=NULL){
//         cout<<"Removed Value is "<<*(int*)prev1->VALUE<<endl;
//         free(prev1);
//     }
//     Print();

//     cout<<"calling SymTable_contains() for KEY = "<<pcKey1<<endl;
//     result =SymTable_contains(oSymTable,pcKey1);
//     cout<<"result  is "<<result<<endl;

//     cout<<"calling SymTable_contains() for KEY = "<<pcKey<<endl;
//     result =SymTable_contains(oSymTable,pcKey);
//     cout<<"result  is "<<result<<endl;

//     cout<<"calling SymTable_contains() for KEY = "<<pcKey5<<endl;
//     result =SymTable_contains(oSymTable,pcKey5);
//     cout<<"result  is "<<result<<endl;

//     Print();
//     int y5=5;
//     cout<<"calling SymTable_replace() for KEY = "<<pcKey2<<endl;
//     prev1 =(iNode*)SymTable_replace(oSymTable,pcKey2,&y);
//     if(prev1!=NULL){       cout<<"Replaced key = "<<pcKey2<<" with new value = "<<*(int*)prev1->VALUE<<endl;
//     }else
//     cout<<"Key Not Found"<<endl;


//     cout<<"calling SymTable_replace() for KEY = "<<pcKey<<"new value = "<<y<<endl;
//     int m=10, *re=&m;
//     prev1 =(iNode*)SymTable_replace(oSymTable,pcKey,&m);
//     if(prev1!=NULL){       cout<<"Replaced key = "<<pcKey<<" with new value = "<<*(int*)prev1->VALUE<<endl;
//     }else
//     cout<<"Key Not Found"<<endl;

//     // const char *pcKey=NULL;
//     // const void *pvValue=NULL;
//     SymTable_map(oSymTable,display,nullptr,nullptr);
//     Print();
//     return 0;
// }