#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &st, int size, int count){
    // base case
    if(count==size/2){
        st.pop();
        return;
    }

    int num=st.top();
    st.pop();

    // recursive call
    solve(st, size, count+1);

    // while returning back push the number popped back onto the stack 
    st.push(num);

}

void deleteMidle(stack<int> &st){
    int size=st.size();
    int count=0;

    solve(st, size, count);
}

void printStack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
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
    st.push(6);

    cout<<"Before deleting the middle element the stack is : "<<endl;
    printStack(st);

    deleteMidle(st);

    cout<<"After deleting the middle element the stack is : "<<endl;
    printStack(st);

    return 0;
}