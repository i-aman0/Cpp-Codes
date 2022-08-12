#include<iostream>
using namespace std;

class Queue{
    public :
    int* arr;
    int qfront;
    int rear;
    int size;

    // constructor
    Queue(){
        size=5;
        arr=new int[size];
        qfront=0;
        rear=0;
    }

    // check if queue is empty
    // queue is empty if front==rear
    bool isEmpty(){
        if(qfront==rear){
            return true;
        }
        else{
            return false;
        }
    }

    // push into queue
    void enqueue(int data){
        if(rear==size){
            cout<<"Queue is full. Can't push "<<data<<" to the queue"<<endl;
        }
        else{
            arr[rear]=data;
            rear++;
        }
    }

    // pop from the queue
    int dequeue(){
        if(qfront==rear){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        else{
            int ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;

            // if queue becomes empty
            // reinitialize front and rear to 0 so that the previous indexes are not wasted
            if(qfront==rear){
                qfront=0;
                rear=0;
            }
            return ans;
        }

    }

    // return front element 
    int front(){
        if(qfront==rear){
            return -1;
        }
        else{
            return arr[qfront];
        }
    }
};

int main()
{
    Queue *q=new Queue();

    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->enqueue(4);
    q->enqueue(5);
    q->enqueue(6);

    cout<<"Front : "<<q->front()<<endl;

    cout<<"Popped element : "<<q->dequeue()<<endl;

    cout<<"Front : "<<q->front()<<endl;

    return 0;
}