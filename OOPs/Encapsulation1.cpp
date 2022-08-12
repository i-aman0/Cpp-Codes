#include<iostream>
using namespace std;

// Encapsulation means hiding the important and sensitive information from rest of the program 
// We achieve this by making the required data members and member functions private 

class Employee{
    private:
    int age=12;
    string name;
    int height;

    public:
    int getAge(){
        return this->age;
    }
};

int main()
{
    Employee e1;
    cout<<e1.getAge()<<endl;
    return 0;
}