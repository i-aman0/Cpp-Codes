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

// function to check height of binary tree
// time complexity --> O(n)
// space complexity --> O(height)
// where n is number of nodes and height is the height of binary tree
int height(node* root){
    // base case
    if(root==NULL){
        return 0;
    }

    int leftHeight=height(root->left);
    int rightHeight=height(root->right);

    int ans=max(leftHeight, rightHeight) + 1;
    // +1 if the height is defined as number of nodes between root node and leaf node
    // no +1 if height is defined as number of edges between root node and leaf node

    return ans;
}

int minHeight(node* root){
    if(root==NULL){
        return 0;
    }

    int ans;
    int leftHeight=minHeight(root->left);
    int rightHeight=minHeight(root->right);

    // if any of the two is zero then don't count on the zero side count the other side 
    // can be the case of skew tree
    if(leftHeight==0 || rightHeight==0){
        ans=max(leftHeight, rightHeight)+1;
    }
    else{
        ans=min(leftHeight, rightHeight)+1;
    }

    return ans;
}

// we make a pair and return the true/false value in the first part of the pair and height of tree in the second part of the pair 

pair<bool, int> isBalanceFast(node* root){
    if(root==NULL){
        pair<bool, int> ans=make_pair(true, 0);
        return ans;
    }

    // left recursive call
    pair<bool, int> left=isBalanceFast(root->left);

    // right recursive call
    pair<bool, int> right=isBalanceFast(root->right);

    // is left tree balanced (true/false)
    bool leftAns=left.first;

    // is right tree balanced (true/false)
    bool rightAns=right.first;

    // is the tree height balanced 
    bool diff=abs(left.second - right.second) <= 1;

    pair<bool, int> ans;

    // storing maximum height of the tree in the second part of the pair 
    ans.second=max(left.second, right.second)+1;

    // if the tree is balanced store true in the first part of the pair 
    if(leftAns && rightAns && diff){
        ans.first=true;
    }
    else{
        ans.first=false;
    }

    return ans;
}

bool isBalance(node* root){
    // return the value stored in the first part of the pair returned by the fast function
    return isBalanceFast(root).first;
}

int main()
{
    // data to be entered
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1

    // creating root node
    node* root=NULL;

    // calling buildTree function with root node as starting node
    root=buildTree(root);

    // level order traversal or BFS
    cout<<"Level order traversal is : "<<endl;
    levelOrderTraversal(root);

    cout<<"Inorder traversal is : "<<endl;
    inorder(root);
    cout<<endl;

    cout<<"Preorder traversal is : "<<endl;
    preorder(root);
    cout<<endl;

    cout<<"Postorder traversal is : "<<endl;
    postorder(root);
    cout<<endl;

    cout<<"The height of binary tree is : "<<height(root)<<endl;

    cout<<"The minimum height of binary tree is : "<<minHeight(root)<<endl;

    if(isBalance(root)){
        cout<<"The tree is balanced"<<endl;
    }
    else{
        cout<<"The tree is not balanced"<<endl;
    }
    return 0;
}