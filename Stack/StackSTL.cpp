#include<iostream>
#include<stack>
using namespace std;

int main()
{
    // creation of stack
    stack<int> s;

    // push operation
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout<<"The size of stack is "<<s.size()<<endl;
    cout<<"The top element of stack is "<<s.top()<<endl;

    cout<<"After one pop operation"<<endl;
    cout<<"The size of stack is "<<s.size()<<endl;
    cout<<"The top element of stack is "<<s.top()<<endl;

    return 0;
}