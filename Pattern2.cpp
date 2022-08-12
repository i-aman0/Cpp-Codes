#include<iostream>
using namespace std;

int main()
{

    
    // initializing the array with the specified values 
    /*int arr[10]={[0 ... 5]=-1, [6 ... 9]=2};
    for(int i=0;i<10;i++)
    {
        cout<<arr[i]<<endl;
    }*/



    int n;
    cout<<"Enter the number of rows"<<endl;
    cin>>n;
    cout<<"The pattern is : "<<endl<<endl;
    for(int i=0;i<2*n;i++)
    {
        for(int j=0;j<2*n;j++)
        {
            if(i+j>=(2*n-1))
            {
                cout<<j<<" ";
            }
            else
            {
                cout<<" ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}