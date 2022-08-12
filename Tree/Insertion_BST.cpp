#include<iostream>
using namespace std;

struct node
{
    char data;
    node* left=NULL;
    node* right=NULL;
};

node* root=NULL;
node* loc=NULL;
node* par=NULL;

void inorder(node* root)
{
    if(root==NULL)
    {
        return;
    }

    inorder(root->left);
    cout<<"\t"<<root->data;
    inorder(root->right);
}

void find(char item)
{
    node* save=NULL;
    node* ptr=root;

    while(ptr!=NULL)
    {
        if(item<ptr->data)
        {
            save=ptr;
            ptr=ptr->left;
        }
        else if(item>ptr->data)
        {
            save=ptr;
            ptr=ptr->right;
        }
        else
        {
            loc=ptr;
            par=save;
            break;
        }
    }
    if(ptr==NULL)
    {
        par=save;
        loc=ptr;  //or NULL both are same 
    }
}

void insert_BST(char item)
{
    find(item); //updates the values of PAR and LOC

    if(loc!=NULL)
    {
        cout<<"Key is already present in the tree"<<endl;
        return;
    }
    else
    {
        node* NEW=new node;
        NEW->data=item;

        if(par==NULL)
        {
            root=NEW;
        }
        else if(item<par->data)
        {
            par->left=NEW;
        }
        else
        {
            par->right=NEW;
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the number of nodes you want to enter"<<endl;
    cin>>n;

    char key;

    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter the Key"<<endl;
        cin>>key;
        insert_BST(key);
    }

    inorder(root);
    return 0;
}