#include<iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;

    Node(){
        this -> data = 0;
        this -> next = nullptr;
    }

    Node(int data){
        this -> data = data;
        this -> next = nullptr; 
    }

    Node(int data, Node* next){
        this -> data = data;
        this -> next = next;
    }
};

class linkedList{
    Node* head;
    Node* tail;

    public:
    linkedList(){
        head = nullptr;
        tail = nullptr;
    }

    void insertHead(int data){
        Node* newNode = new Node(data);

        if(head == nullptr){
            head = newNode;
            tail = newNode;
            return;
        }

        newNode -> next = head;
        head = newNode;
    }

    void insertTail(int data){
        Node* newNode = new Node(data);

        if(tail == nullptr){
            head = newNode;
            tail = newNode;
            return;
        }

        tail -> next = newNode;
        tail = newNode;
    }
};

int main()
{
    
    return 0;
}