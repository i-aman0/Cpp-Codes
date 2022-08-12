#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cout<<"Enter the number of test cases"<<endl;
	cin>>t;
	int arr[t];
	cout<<"Enter the numbers"<<endl;
	for(int i=0;i<t;i++)
	{
	    cin>>arr[i];
	}
	for(int i=0;i<t;i++)
	{
	    int num=arr[i];
	    int counter;
	    while(num!=0)
	    {
	        int d=num%10;
	        num=num/10;
	        if(d==4)
	        {
	            counter++;
	        }
	        
	    }
	    cout<<counter<<endl;
        counter=0;
	}
	return 0;
}
