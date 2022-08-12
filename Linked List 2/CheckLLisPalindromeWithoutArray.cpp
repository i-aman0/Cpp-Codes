#include<iostream>
#include<vector>
using namespace std;

// in this approach the steps are:
// 1. Find the middle of the linked list
// 2. Reverse the linked list after the middle element
// 3. Check whether both the halves are equal or not
//    if equal the linked list is palindrome otherwise not
// 4. Reverse the second half again so that the linked list does not get affected

// Time Complexity -- O(n)
// Space Complexity -- O(1)

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

Node* getMiddle(Node* head){
    Node* slow=head;
    Node* fast=head->next;

    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

Node* reverseList(Node* head){
    Node* curr=head;
    Node* prev=NULL;
    Node* next=NULL;

    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

bool isPalindrome(Node* head){
    if(head==NULL || head->next==NULL){
        return true;
    }

    // 1. Find the middle of the linked list 
    Node* middle=getMiddle(head);

    // 2. Reverse the linked list after the middle node
    Node* temp=middle->next;
    middle->next=reverseList(temp);

    // 3. Compare both the halves
    Node* head1=head;
    Node* head2=middle->next;

    while(head2!=NULL){
        if(head1->data != head2->data){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }

    // 4. Reverse the linked list after the middle node again 
    temp=middle->next;
    middle->next=reverseList(temp);

    // return true
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

    cout<<"Head points at value : "<<head->data<<endl;
    cout<<"Tail points at value : "<<tail->data<<endl;

    if(isPalindrome(head)){
        cout<<"The given linked list is palindrome"<<endl;
    }
    else{
        cout<<"The given linked list is not palindrome"<<endl;
    }

    return 0;
}