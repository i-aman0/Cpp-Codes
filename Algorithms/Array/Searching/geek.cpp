#include <iostream>
using namespace std;

int geek(int arr[], int n, int x)
{
    int counter=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>x)
        {
            counter++;
        }
    }
    return counter;
}

int main() {
    int t;
	cin>>t;
	while(t--)
	{
	    int n,x;
	    cin>>n>>x;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    cout<<geek(arr,n,x);
	}
	//code
	return 0;
}