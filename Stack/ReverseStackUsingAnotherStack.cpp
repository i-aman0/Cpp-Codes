#include<iostream>
#include<stack>
using namespace std;

stack<int> reverseStack(stack<int> st){
    stack<int> s;
    while(!st.empty()){
        int topNum=st.top();
        s.push(topNum);
        st.pop();
    }
    return s;
}

void printStack(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}

int main()
{
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout<<"After reversing the stack is : "<<endl;
    printStack(st);

    st=reverseStack(st);

    cout<<"After reversing the stack is : "<<endl;
    printStack(st);

    return 0;
}