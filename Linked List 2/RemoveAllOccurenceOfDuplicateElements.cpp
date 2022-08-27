#include<iostream>
using namespace std;


// given a sorted singly linked list, remove all the occurences of duplicate elements from the linked list

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

Node* removeDuplicate(Node* head){
    if(head==NULL){
        return NULL;
    }

    // create a dummy node and make it point to the head to keep the record of the original head
    Node* dummy=new Node(-1);
    dummy->next=head;

    // create a prev node that will point to the last node which has no duplicates
    Node* prev=dummy;

    // current node for traversal of the linked list
    Node* current=head;

    while(current!=NULL){

        // while previous and current values are same, keep updating the current 
        while(current->next!=NULL && prev->next->data==current->next->data){
            current=current->next;
        }

        // if the current has unique value, i.e. no duplicate found till now and it is not updated yet in above code,
        // move previous pointer to next node
        if(prev->next==current){
            prev=prev->next;
        }
        // otherwise make previous the next of current
        else{
            prev->next=current->next;
        }

        // move current one step ahead
        current=current->next;
    }

    //when the complete list is traversed, update the head to next of dummy
    head=dummy->next;
    return head;
}

void print(Node* &head){  // took reference of head so that no extra copy is created
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* node1=new Node(40);

    //cout<<"The data stored in node is : "<<node1->data<<endl;
    //cout<<"The next pointer of node points to : "<<node1->next<<endl;

    Node* head=node1; // creating head node which is pointing to the first node created above
    Node* tail=node1; // in case of single node tail pointer also points to that only 

    insertAtHead(head,30);
    print(head);

    insertAtHead(head,20);
    print(head);

    insertAtHead(head,10);
    print(head);

    insertAtTail(tail,50);
    print(head);

    insertAtTail(tail,50);
    print(head);

    insertAtTail(tail,50);
    print(head);

    insertAtTail(tail,60);
    print(head);

    insertAtTail(tail,60);
    print(head);

    insertAtTail(tail,60);
    print(head);

    insertAtTail(tail,70);
    print(head);

    insertAtTail(tail,70);
    print(head);

    insertAtTail(tail,80);
    print(head);

    head=removeDuplicate(head);
    print(head);

    return 0;
}