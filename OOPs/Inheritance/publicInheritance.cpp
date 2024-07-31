#include<iostream>
using namespace std;

class Person{

    public:
    int age = 19;
    int height;
    int weight;

    int getAge(){
        cout<<"The age has been returned"<<endl;
        return this->age;
    }

    void setHeight(int h){
        this->height=h;
    }
    
    int getHeight(){
        return this -> height;
    }

};

class Male : public Person{
    public:
    string name;

    void getSleep(){
        cout<<"Person is sleeping"<<endl;
    }
};

int main()
{
    Male m1;
    cout<<m1.getAge()<<endl;
    m1.getSleep();
    m1.setHeight(5);
    cout << "The height is : " << m1.getHeight() << endl;
    return 0;
}