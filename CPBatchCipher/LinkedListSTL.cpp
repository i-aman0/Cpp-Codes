#include<iostream>
#include<list>
using namespace std;

void display(list<int> &ll){
    for(int element : ll){
        cout << element << " ";
    }
    cout << endl;
}

int main()
{
    list<int> ll;

    ll.push_back(2);
    ll.push_front(1);
    ll.push_back(3);

    display(ll);
    return 0;
}