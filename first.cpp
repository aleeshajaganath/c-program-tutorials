#include<iostream>
using namespace std;

void arrayPointer(){

    // array of pointer
    

    int arr[10]={0,1,2,3,4,5,6,7,8,9};
    int *p= arr;

    //display array using pointer
    for(int i=0;i<9;i++)
        cout << *(p+i) << endl;

    cout<< "size of *p " <<sizeof(p);
        
}

void pointer(){

    //pointer concepts

    int x=5, *a;

    // assign the address of the variable to a pointer
    a=&x;
    cout << "a = " << a << endl;

    //*a and x contains same value
    cout << "*a = " << *a << endl;
    cout << "x = " << *a << endl;
    
    //& denote the address of a variable
    cout << "&a = " << &a << endl;
    cout << "&x = " << &x << endl;

    // Address of a variable of type t has type t *
    double pi = 3.14159, *pii,*pnn ;
    pii=&pi;

    cout << "&pi = " << &pi << endl;
    cout << "&pii = " << &pii << endl;

    // double *b;
    int n=5;
    int *pn = &n;
    pnn= (double*)pn;
    cout << "   *pnn = " << *pnn << endl;
    cout << "   *pii = " << *pii << endl;

    cout << "sum of pointer is *b + *pii " <<  *a + *pii << endl;


    int *px = &n ;
    pii =(double*)px; //∗ pn originally of type ( int ∗) ∗/

    cout<< "new *pii " <<*pii << endl;
}

int add(int a , int b){
// add 2 numbers
    return a+b;
}

void justfun(){
    // just a function to display
    cout<<"inside justfun()";
}

void function(void (*functn)()){

    // function with pointer function as argument
    functn();
}

void functionpointer(){

    //  pointer function 

    // int (*FuncPtr) (int,int);  
    int (*refer)(int,int); //declaration 
    refer=add; //assign add function to refer
    int sum=refer(5,5); //call pointer to add 'refer'

    cout << "Sum is  = " << sum << endl;

    // Passing a function pointer as a parameter
    function(justfun);

}
int main(){


    // cout <<"\n success \n";
    pointer();
    cout <<  "Address of a main() function is : " << &main << endl;
    // function pointer
    functionpointer();
    // ponter array
    arrayPointer();
    cout <<   endl;

    return 0;
}
