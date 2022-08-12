#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    //destructor
    ~Node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory free for node having value : "<<value<<endl;
    }
};

// data is the data to be inserted and element is the value after which data is to be inserted 
void insertNode(int data, int element, Node* &tail){
    //empty list
    if(tail==NULL){
        Node* temp=new Node(data);
        tail=temp;
        temp->next=temp;
    }

    // non-empty list 
    else{
        // assuming that the element is present in the list
        Node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }

        // element found and curr is pointing to the node having the element after which data is to be stored 
        Node* temp=new Node(data);
        temp->next=curr->next;
        curr->next=temp;
    }
}

void deleteNode(Node* &tail, int value){

    //empty list
    if(tail==NULL){
        cout<<"List is empty. Cannot delete."<<endl;
        return;
    }

    //non-empty list
    else{
        //assuming the value is present in the list 

        Node* prev=tail;
        Node* curr=prev->next;

        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }

        // list having single node
        if(curr==prev){
            tail=NULL;
        }

        // list having >=2 nodes
        else if(tail==curr){
            tail=curr->next;
        }

        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}


void print(Node* tail){

    //empty list 
    if(tail==NULL){
        cout<<"Linked list is empty"<<endl;
        return;
    }

    Node* temp=tail;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    } while(tail!=temp);
    cout<<endl;
}

int main()
{
    Node* tail=NULL;

    //insertion in empty linked list
    insertNode(2, 5, tail); // here the element(5) does not matter we can give any element 
    print(tail);

    insertNode(5, 2, tail);
    print(tail);

    insertNode(7, 5, tail);
    print(tail);

    insertNode(6, 5, tail);
    print(tail);

    insertNode(3, 2, tail);
    print(tail);

    deleteNode(tail,5 );
    print(tail);

    return 0;
}