#include<iostream>
using namespace std;

struct node
{
    char data;
    node* left=NULL; //bcoz every new node is added as leaf node so left and right will point to null
    node* right=NULL;
};

node* root=NULL;

//Recursive function to traverse
void preorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<"\t";
    preorder(root->left); //process the left subtree of root
    preorder(root->right);
}

void inorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left); //process the left subtree of root
    cout<<root->data<<"\t";
    inorder(root->right);
}

void postorder(node* root)
{
     if(root==NULL)
    {
        return;
    }
    postorder(root->left); //process the left subtree of root
    postorder(root->right);
    cout<<root->data<<"\t";
}

int main()
{
    node* NEW=new node;
    NEW->data='A';
    root=NEW;

    node* NEW2=new node;
    NEW2->data='B';
    NEW->left=NEW2;

    node* NEW3=new node;
    NEW3->data='C';
    NEW->right=NEW3;

    node* NEW4=new node;
    NEW4->data='D';
    NEW2->right=NEW4;

    node* NEW5=new node;
    NEW5->data='E';
    NEW3->left=NEW5;

    node* NEW6=new node;
    NEW6->data='F';
    NEW3->right=NEW6;

    node* NEW7=new node;
    NEW7->data='G';
    NEW6->left=NEW7;

    cout<<"PreOrder Traversal"<<endl;
    preorder(NEW);

    cout<<"\nInOrder Traversal"<<endl;
    inorder(NEW);

    cout<<"\nPostOrder Traversal"<<endl;
    postorder(NEW);

    return 0;
}