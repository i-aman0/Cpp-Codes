#include<iostream>
using namespace std;

// In the below code the + operator is overloaded to perform subtraction 
// Similarly we can also overload it to add complex numbers 

class A{
    public:
    int a;
    int b;

    void operator + (A &obj){
        int value1=this->a;
        int value2=obj.a;

        cout<<"The output is : "<<value2-value1<<endl;
    }

    void operator() (){
        cout<<"I am a bracket and the value is : "<<this->a<<endl;
    }
};

int main()
{

    A obj1, obj2;
    obj1.a=8;
    obj2.a=10;

    obj1+obj2; //calls the overloaded + operator 

    obj1();  // calls the overloaded () operator  
    
    return 0;
}