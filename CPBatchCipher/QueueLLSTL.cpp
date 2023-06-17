#include<iostream>
#include<list>
using namespace std;

class Queue{
    private:
    list<int> ll;

    public:
    Queue(){

    }

    void enqueue(int data){
        ll.push_back(data);
    }

    void dequeue(){
        if(ll.empty()){
            cout << "Queue is empty" << endl;
            return;
        }

        ll.pop_front();
    }

    int front(){
        return ll.front();
    }

    int back(){
        return ll.back();
    }

    bool isEmpty(){
        return ll.empty();
    }
};

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue(); // pops 1 from the front of the queue
    q.enqueue(4);
    q.enqueue(5);

    while(!q.isEmpty()){
        cout << q.front() << " ";
        q.dequeue();
    }
    return 0;
}