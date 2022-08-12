#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &st, int x){
    bool isEmpty=st.empty();

    if(isEmpty){
        st.push(x);
        return;
    }
    
    int num=st.top();
    st.pop();

    solve(st, x);

    st.push(num);
}

void pushAtBottom(stack<int> &st, int x){
    solve(st,x);
}

int main()
{
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    pushAtBottom(st,9);

    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }

    return 0;
}