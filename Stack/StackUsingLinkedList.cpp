#include<iostream>
using namespace std;

class Stack{
    public:
    Stack* next;
    int data;
    Stack* top;

    Stack(){
        top=NULL;
    }

    void push(int n){
        Stack* temp=new Stack();
        if(temp==NULL){
            cout<<"Stack overflow"<<endl;
            return;
        }

        temp->data=n;
        temp->next=top;
        top=temp;
    }

    int pop(){
        int n=-1;
        if(top==NULL){
            cout<<"Stack underflow"<<endl;
        }
        else{
            n=top->data;
            top=top->next;
        }
        return n;
    }

    int peek(){
        int n=-1;
        if(top==NULL){
            n=-1;
        }
        else{
            n=top->data;
        }
        return n;
    }

    bool isEmpty(){
        if(top==NULL){
            return true;
        }
        else{
            return false;
        }
    }
};

int main()
{

    Stack* st=new Stack();

    st->push(1);
    st->push(2);
    st->push(3);
    st->push(4);
    st->push(5);

    cout<<st->peek()<<endl;

    st->pop();

    cout<<st->peek()<<endl;
    
    if(st->isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }

    st->pop();
    st->pop();
    st->pop();
    st->pop();

    if(st->isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }

    
    return 0;
}