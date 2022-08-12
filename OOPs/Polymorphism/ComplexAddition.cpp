#include<iostream>
using namespace std;

class Add{
    public:
    int real;
    int img;

    void operator+ (Add &obj){
        int r1=this->real;
        int r2=obj.real;

        int i1=this->img;
        int i2=obj.img;

        cout<<"The addition of "<<r1<<"+"<<i1<<"i and "<<r2<<"+"<<i2<<"i is : "<<r1+r2<<"+"<<i1+i2<<"i"<<endl;
    }
};

int main()
{

    Add obj1, obj2;
    cout<<"Enter the real value of object  1"<<endl;
    cin>>obj1.real;

    cout<<"Enter the imaginary value of object 1"<<endl;
    cin>>obj1.img;

    cout<<"Enter the real value of object  2"<<endl;
    cin>>obj2.real;

    cout<<"Enter the imaginary value of object 2"<<endl;
    cin>>obj2.img;

    obj1+obj2;
    
    return 0;
}