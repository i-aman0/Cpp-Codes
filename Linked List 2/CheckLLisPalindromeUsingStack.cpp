#include<iostream>
#include<stack>
using namespace std;

// we can also use stack to check whether the linked list is palindrome or not 
// store all the elements of linked list in the stack 
// traverse the linked list from beginning and compare the values with the top element of the stack 
// if both the elements are equal, increse the temp of linked list and pop one element from the stack
// as soon as they are not equal , it means that the linked list is not palindrome

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }


    // destructor 
    ~Node(){
        int value=this->data;

        // freeing memory 
        if(this->next != NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free for node with data : "<<value<<endl;
    }
};



void insertAtHead(Node* &head, int data){
    //creating a new node
    Node* temp=new Node(data);
     
    temp->next=head;
    head=temp;
}



void insertAtTail(Node* &tail, int data){
    // create a new node
    Node* temp=new Node(data);

    tail->next=temp;
    tail=tail->next;
}



void insertAtPosition(Node* &tail, Node* &head, int position, int data){

    // inserting at start
    if(position == 1){
        insertAtHead(head, data);
        return;
    }

    Node* temp=head;
    int count=1;
    while(count<position-1){
        temp=temp->next;
        count++;
    }

    // inserting at tail
    if(temp->next==NULL){
        insertAtTail(tail, data);
        return;
    }

    // inserting at a position 
    Node* nodeToInsert=new Node(data);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;

}



void deleteNode(int position, Node* &head, Node* &tail){

    // deleting start or first node 
    if(position==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;

        // freeing memory (the delete keyword calls the destructor of the object)
        delete temp;
    }

    else{
        // deleting any other node (last or any middle node)

        Node* curr=head;
        Node* prev=NULL;

        int count=1;
        while(count<position){
            prev=curr;
            curr=curr->next;
            count++;
        }

        if(curr->next==NULL){
            tail=prev;
        }

        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

void print(Node* &head){  // took reference of head so that no extra copy is created
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

bool isPalindrome(Node* head){
    stack<int> st;
    Node* temp=head;

    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }

    temp=head;

    while(temp!=NULL && !st.empty()){
        if(temp->data != st.top()){
            return false;
        }
        else{
            temp=temp->next;
            st.pop();
        }
    }
    return true;
}

int main()
{
    Node* node1=new Node(20);

    //cout<<"The data stored in node is : "<<node1->data<<endl;
    //cout<<"The next pointer of node points to : "<<node1->next<<endl;

    Node* head=node1; // creating head node which is pointing to the first node created above
    Node* tail=node1; // in case of single node tail pointer also points to that only 


    insertAtHead(head,10);
    print(head);

    insertAtHead(head,5);
    print(head);

    insertAtTail(tail,10);
    print(head);

    insertAtTail(tail,5);
    print(head);

    insertAtTail(tail,5);
    print(head);

    if(isPalindrome(head)){
        cout<<"The given linked list is palindrome"<<endl;
    }
    else{
        cout<<"The given linked list is not palindrome"<<endl;
    }

    return 0;
}