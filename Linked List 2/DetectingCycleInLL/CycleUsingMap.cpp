#include<iostream>
#include<map>
using namespace std;



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

bool isCycle(Node* head){
    if(head==NULL){
        return false;
    }

    map<Node*, bool> visited;
    Node* temp=head;

    while(temp!=NULL){

        // means the node is already visited and the value stored in the map to its corresponding key is true  
        if(visited[temp]==true){
            cout<<"The cycle is present at element "<<temp->data<<endl;
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    return false;
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
    Node* node1=new Node(10);

    //cout<<"The data stored in node is : "<<node1->data<<endl;
    //cout<<"The next pointer of node points to : "<<node1->next<<endl;

    Node* head=node1; // creating head node which is pointing to the first node created above
    Node* tail=node1; // in case of single node tail pointer also points to that only 

    insertAtHead(head,20);
    print(head);

    insertAtHead(head,30);
    print(head);

    insertAtHead(head,40);
    print(head);

    insertAtTail(tail,50);
    print(head);

    insertAtTail(tail,60);
    print(head);

    insertAtPosition(tail, head, 3, 70);
    print(head);

   // cout<<"Head points at value : "<<head->data<<endl;
    //cout<<"Tail points at value : "<<tail->data<<endl;

    //deleteNode(7,head,tail);
    //print(head);

    cout<<"Head points at value : "<<head->data<<endl;
    cout<<"Tail points at value : "<<tail->data<<endl;

    tail->next=head->next;
    

    if(isCycle(head)){
        cout<<"There is a cycle in the linked list"<<endl;
    }
    else{
        cout<<"There is no cycle in the linked list"<<endl;
    }

    return 0;
}