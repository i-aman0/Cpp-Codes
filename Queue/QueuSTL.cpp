#include<iostream>
#include<queue>
using namespace std;

// in queue push at rear and pop from front

int main()
{
    queue<int> q;

    q.push(1);
    cout<<"Front : "<<q.front()<<endl;
    cout<<"Rear : "<<q.back()<<endl;

    q.push(2);
    cout<<"Front : "<<q.front()<<endl;
    cout<<"Rear : "<<q.back()<<endl;

    q.push(3);
    cout<<"Front : "<<q.front()<<endl;
    cout<<"Rear : "<<q.back()<<endl;

    q.push(4);
    cout<<"Front : "<<q.front()<<endl;
    cout<<"Rear : "<<q.back()<<endl;

    q.push(5);
    cout<<"Front : "<<q.front()<<endl;
    cout<<"Rear : "<<q.back()<<endl;

    q.pop();
    cout<<"Front : "<<q.front()<<endl;
    cout<<"Rear : "<<q.back()<<endl;

    q.pop();
    cout<<"Front : "<<q.front()<<endl;
    cout<<"Rear : "<<q.back()<<endl;

    cout<<"The size of queue is : "<<q.size()<<endl;

    if(q.empty()){
        cout<<"The queue is empty"<<endl;
    }
    else{
        cout<<"The queue is not empty"<<endl;
    }

    q.pop();
    q.pop();
    q.pop();

    if(q.empty()){
        cout<<"The queue is empty"<<endl;
    }
    else{
        cout<<"The queue is not empty"<<endl;
    }



    return 0;
}