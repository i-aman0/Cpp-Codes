#include<iostream>
using namespace std;

struct node
{
    string name;
    int roll;
    node* link;
};

node* start=NULL;

void traverse()
{
    node* ptr=start;
    while(ptr!=NULL)
    {
        cout<<ptr->name<<" "<<ptr->roll<<endl;
        ptr=ptr->link;
    }
}

void middle()
{
    node* slow=start;
    node* fast=start;
    if (start!=NULL)
        {
            while (fast != NULL && fast->link != NULL)
            {
                fast = fast->link->link;
                slow = slow->link;
            }
            cout<<"The middle Data Element is : "<<slow->name<<" "<<slow->roll<<endl;
        }
}
int main()
{
    node* n1=new node;
    n1->name="Aman";
    n1->roll=110;

    node* n2=new node;
    n2->name="Sirius";
    n2->roll=111;

    node* n3=new node;
    n3->name="Remus";
    n3->roll=112;

    node* n4=new node;
    n4->name="James";
    n4->roll=113;

    node* n5=new node;
    n5->name="Harry";
    n5->roll=114;

    start=n1;
    n1->link=n2;
    n2->link=n3;
    n3->link=n4;
    n4->link=n5;
    n5->link=NULL;

    traverse();
    middle();

    return 0;
}