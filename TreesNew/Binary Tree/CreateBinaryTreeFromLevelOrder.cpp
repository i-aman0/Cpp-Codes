#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        // Constructor
        node(int data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};

// function to build the tree
node* buildTree(node* root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;

    root=new node(data);

    // -1 means that the node is leaf node i.e. the next node is NULL
    if(data==-1){
        return NULL;
    }

    cout<<"Enter the data for inserting in the left of "<<data<<endl;
    root->left=buildTree(root->left);

    cout<<"Enter the data for inserting in the right of "<<data<<endl;
    root->right=buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    
    //pushing a separator to mark the levels
    q.push(NULL);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        // if previous level is completely traversed, hit enter
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                // queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

// LNR
void inorder(node* root){
    // base case
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

// NLR
void preorder(node* root){
    if(root == NULL){
        return;
    }
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// LRN
void postorder(node* root){
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void buildFromLevelOrder(node* &root){
    queue<node*> q;
    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        cout<<"Enter left node for "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left=new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right=new node(rightData);
            q.push(temp->right);
        }
    }
}

int height(node* root){
    if(root==NULL){
        return 0;
    }

    int leftHeight=height(root->left);
    int rightHeight=height(root->right);

    int ans=max(leftHeight, rightHeight)+1;
    
    return ans;
}

int main()
{
    node* root=NULL;

    buildFromLevelOrder(root);

    cout<<"The level order traversal of binary tree is : "<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    
    cout<<"The height of binary tree is : "<<height(root)<<endl;


}