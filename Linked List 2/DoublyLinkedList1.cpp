#include<iostream>
using namespace std;

class Node{
    public:
    Node* next;
    Node* prev;
    int data;

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }

    ~Node(){
        int value=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory free for node having value : "<<value<<endl;
    }
};



void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}



int getLength(Node* head){
    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}



void insertAtHead(Node* &head, Node* &tail, int data){
    if(head==NULL){
        Node* temp=new Node(data);
        head=temp;
        tail=temp;
    }
    else{
        Node* temp=new Node(data);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}



void insertAtTail(Node* &head, Node* &tail, int data){
    if(tail==NULL){
        Node* temp=new Node(data);
        head=temp;
        tail=temp;
    }
    else{
        Node* temp=new Node(data);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}


void insertAtPosition(Node* &head, Node* &tail, int position, int data){
    if(position==1){
        insertAtHead(head, tail, data);
        return;
    }
    else{
        Node* temp=head;
        int count=1;
        while(count<position-1){
            temp=temp->next;
            count++;
        }

        if(temp->next==NULL){
            insertAtTail(head, tail, data);
            return;
        }

        Node* nodeToInsert=new Node(data);
        nodeToInsert->next=temp->next;
        temp->next->prev=nodeToInsert;
        nodeToInsert->prev=temp;
        temp->next=nodeToInsert;
    }
}


void deleteNode(int position, Node* &head, Node* &tail){
    // deleting first or start node
    if(position==1){
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }

    //deleting middle or last node 
    else{
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

            curr->prev=NULL;
            prev->next=curr->next;
            curr->next=NULL;

            delete curr;
    }
}



int main()
{
    //Node* node1=new Node(10);  
    // when no node exist

    Node* head=NULL;
    Node* tail=NULL;

    print(head);
    //cout<<"The length of linked list is : "<<getLength(head)<<endl;

    insertAtHead(head, tail, 9);
    print(head);
    cout<<"Head : "<<head->data<<", Tail : "<<tail->data<<endl<<endl;

    insertAtHead(head, tail, 8);
    print(head);
    cout<<"Head : "<<head->data<<", Tail : "<<tail->data<<endl<<endl;

    insertAtTail(head, tail,11);
    print(head);
    cout<<"Head : "<<head->data<<", Tail : "<<tail->data<<endl<<endl;

    insertAtTail(head, tail,12);
    print(head);
    cout<<"Head : "<<head->data<<", Tail : "<<tail->data<<endl<<endl;

    insertAtPosition(head, tail, 2, 50);
    print(head);
    cout<<"Head : "<<head->data<<", Tail : "<<tail->data<<endl<<endl;

    insertAtPosition(head, tail, 1, 55);
    print(head);
    cout<<"Head : "<<head->data<<", Tail : "<<tail->data<<endl<<endl;

    insertAtPosition(head, tail, 7, 60);
    print(head);
    cout<<"Head : "<<head->data<<", Tail : "<<tail->data<<endl<<endl;


    deleteNode(1,head,tail);
    print(head);
    cout<<"Head : "<<head->data<<", Tail : "<<tail->data<<endl<<endl;

    deleteNode(3,head,tail);
    print(head);
    cout<<"Head : "<<head->data<<", Tail : "<<tail->data<<endl<<endl;

    deleteNode(5,head,tail);
    print(head);
    cout<<"Head : "<<head->data<<", Tail : "<<tail->data<<endl<<endl;
    
    return 0;
}