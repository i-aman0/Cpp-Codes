#include<iostream>
using namespace std;

struct node
{
    int data;
    node* left=NULL;
    node* right=NULL;
};

node* root=NULL;

/*void inorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<"\t";
    inorder(root->right);
}*/

node* searching(node* root,int item)
{
    node* ptr=root;
    node* loc=NULL;
    while(ptr!=NULL)
    {
        if(item=ptr->data)
        {
            loc=ptr;
            break;
        }
        else if(item<ptr->data)
        {
            ptr=ptr->left;
        }
        else
        {
            ptr=ptr->right;
        }
    }
    return loc;
}


int main()
{
    node* n1=new node;
    n1->data=50;
    root=n1;

    node* n2=new node;
    n2->data=30;
    n1->left=n2;

    node* n3=new node;
    n3->data=60;
    n1->right=n3;

    node* n4=new node;
    n4->data=25;
    n2->left=n4;

    node* n5=new node;
    n5->data=40;
    n2->right=n5;

    node* n6=new node;
    n6->data=65;
    n3->right=n6;

    //inorder(n1);

    int item;
    cout<<"Enter the Item to be Searched"<<endl;
    cin>>item;

    node* result=searching(n1,item);

    if(result==NULL)
    {
        cout<<"The element "<<item<<" is not present in the binary search tree"<<endl;
    }
    else
    {
        cout<<"The element "<<item<<" is present at location "<<result<<endl;
    }

    return 0;
}