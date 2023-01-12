#include<iostream>
#include<vector>
using namespace std;

class Example{
    public:
    int n;
    
    vector<int> a = vector<int> (10, 0);
};

int main()
{
    Example obj;
    int a = 10;
    int* ptrA = &a;
    cout << "a = " << *ptrA <<endl;
    cout << "Address of a is " << &a << endl;
    cout << "Address of a is " << ptrA << endl;
    cout << "Address of ptrA is " << &ptrA << endl;

    double c = 22.1;
    double* ptrC = &c;
    cout << "c = " << c <<endl;

    // size of pointer of every type is equal to the size of int in that system 
    cout << "Size of int " << sizeof(int) << endl;
    cout << "Size of int* " << sizeof(int*) << endl;
    cout << "Size of double " << sizeof(double) << endl;
    cout << "Size of double* " << sizeof(double*) << endl;

    cout << "Size of obj " << sizeof(obj) << endl;
    cout << "Size of Example " << sizeof(Example) << endl;
    cout << "Size of Example* " << sizeof(Example*) << endl;


    vector<int> ea = vector<int> (100, 0);
    cout << "Size of vector " << sizeof(ea) <<endl;
    return 0;
}