// STATIC creation of link list

#include<iostream>
#include<string>
using namespace std;

struct node
{
    string name;  //every node is having 3 fields
    int roll;
    node* link;

};

node* start=NULL; //can be given any name start is by convention

void traverse()
{
    node* ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        cout<<ptr->name<<" "<<ptr->roll<<endl;
        ptr=ptr->link;
    }
}

void search(int r)
{
    node* ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->roll==r)
        {
            cout<<"Roll No. : "<<r<<endl;
            cout<<"Name     : "<<ptr->name<<endl;
            break;
        }
        ptr=ptr->link;
    }
    if(ptr==NULL)
    {
        cout<<"No data with roll number "<<r<<" is found"<<endl;
    }
}

int main()
{
    node* n1=new node; //a node will be instantiated and new returns its address which is storeed in n1
    n1->name="Aman";
    n1->roll=101;

    node* n2=new node;
    n2->name="Habibul";
    n2->roll=102;

    node* n3=new node;
    n3->name="Naved";
    n3->roll=103;

    node* n4=new node;
    n4->name="Raja";
    n4->roll=104;

    //Managing the pointers
    start=n1;
    n1->link=n2;
    n2->link=n3;
    n3->link=n4;
    n4->link=NULL;

    traverse();
    
    int r;
    cout<<"Enter roll number to be searched"<<endl;
    cin>>r;
    search(r);

    return 0;
}