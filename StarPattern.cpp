#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of rows"<<endl;
    cin>>n;
    cout<<endl<<endl;
    cout<<"The pattern is : "<<endl<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(j==1 || i==j)
            {
                cout<<" * ";
            }
            else {
                cout<<" "<<j-1<<" ";
            }
        }
        cout<<endl;
    }


    cout<<endl<<endl;
    return 0;
}