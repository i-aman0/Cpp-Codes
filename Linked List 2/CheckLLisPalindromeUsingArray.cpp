#include<iostream>
#include<vector>
using namespace std;

// to check whether a linked list is palindrome or not using array, we declare an array
// and check if that array is palindrome or not 
// to check if the array is palindrome or not traverse the array from both the ends 
// and see if the element at first and last are equal or not 
// if they are equal, check for the second and the second last element
// and keep on checking the same 

// Time complexity -- O(n)
// Space complexity -- O(n)

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

bool checkPalindrome(vector<int> arr){
    int n=arr.size();
    int start=0;
    int end=n-1;
    while(start<=end){
        if(arr[start]!=arr[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

bool isPalindrome(Node* head){
    if(head==NULL || head->next==NULL){
        return true;
    }

    vector<int> arr;

    Node* temp=head;

    while(temp!=NULL){
        arr.push_back(temp->data);
        temp=temp->next;
    }

    return checkPalindrome(arr);
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