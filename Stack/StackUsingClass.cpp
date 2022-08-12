#include<iostream>
using namespace std;

class Stack{
    public:

    int *arr;
    int top;
    int size;

    //Constructor
    Stack(int size){
        this->size=size;
        top=-1;
        arr=new int[size];
    }  

    //Push
    void push(int element){
        if(size-top>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    //Pop
    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    //IsEmpty
    bool isEmpty(){
        if(top<0){
            return true;
        }
        else{
            return false;
        }
    }

    //Top element
    int peek(){
        if(top>=0 && top<size){
            return arr[top];
        }
        else{
            return -1;
        }
    }

};

int main()
{
    Stack* st=new Stack(5);

    st->push(5);
    st->push(4);
    st->push(3);
    st->push(2);
    st->push(1);

    cout<<"The element at the top of the stack is "<<st->peek()<<endl;

    st->pop();
    cout<<"The element at the top of the stack is "<<st->peek()<<endl;

    st->pop();
    cout<<"The element at the top of the stack is "<<st->peek()<<endl;

    st->pop();
    cout<<"The element at the top of the stack is "<<st->peek()<<endl;

    if(st->isEmpty()){
        cout<<"The stack is empty "<<endl;
    }
    else{
        cout<<"The stack is not empty"<<endl;
    }

    st->pop();
    cout<<"The element at the top of the stack is "<<st->peek()<<endl;

    st->pop();
    cout<<"The element at the top of the stack is "<<st->peek()<<endl;

    if(st->isEmpty()){
        cout<<"The stack is empty "<<endl;
    }
    else{
        cout<<"The stack is not empty"<<endl;
    }

    return 0;
}