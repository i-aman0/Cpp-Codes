#include<iostream>
#include<list>
using namespace std;

class Stack{
    private:
    list<int> ll;

    public:

    Stack(){

    }

    void push(int x){
        ll.push_front(x);
    }

    void pop(){
        if(ll.empty()){
            cout << "Stack UnderFlow" << endl;
            return;
        }

        ll.pop_front();
    }

    int top(){
        if(ll.empty()){
            cout << "Stack UnderFlow" << endl;
            return -1;
        }

        return ll.front();
    }

    int size(){
        return ll.size();
    }

    bool isEmpty(){
        return ll.empty();
    }
};

int main()
{
    Stack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);

    while(!stk.isEmpty()){
        cout << stk.top() << " ";
        stk.pop();
    }
    return 0;
}