#include<iostream>
using namespace std;

struct node
{
    char data;
    node* link;
};

node* start=NULL;

void traverse()
{
    node* ptr=start;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<endl;
        ptr=ptr->link;
    }
}

void insert_last()
{
    node* nd=new node;
    cout<<"\nEnter the data you want to insert"<<endl;
    cin>>nd->data;

    //Checking if list is empty
    if(start==NULL)
    {
        nd->link=NULL;
        start=nd;
    }
    else
    {
        //find address of last node
        node* ptr=start;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        nd->link=NULL;
        ptr->link=nd;
    }
}

void insert_beginning()
{
    node* nd=new node;
    cout<<"\nEnter the data you want to insert"<<endl;
    cin>>nd->data;

    //Checking if list is empty
    if(start==NULL)
    {
        nd->link=NULL;
        start=nd;
    }
    else
    {
        nd->link=start;
        start=nd;
    }
}

int main()
{
    int choice=0;
    int n;
    do
    {
        cout<<"\n\n 1. Create a Linked List"<<endl;
        cout<<"\n 2. Insert at the beginning of a Linked List"<<endl;
        cout<<"\n 3. Insert at the end of Linked List"<<endl;
        cout<<"\n 9. Display"<<endl;
        cout<<"\n 0. Exit"<<endl;
        cout<<"Enter your choice"<<endl;
        cin>>choice;

        switch (choice)
        {
            case 1:
            {
                cout<<"\nEnter the Number of nodes"<<endl;
                cin>>n;
                for(int i=0;i<n;i++)
                {
                    insert_beginning();
                }
                break;
            }
            case 2:
            {
                insert_beginning();
                break;
            }
            case 3:
            {
                insert_last();
                break;
            }
            case 9:
            {
                traverse();
                break;
            }
        }
    } while (choice!=0);
    

    return 0;
}