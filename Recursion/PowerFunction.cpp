#include<iostream>
using namespace std;

int calculatePower(int a, int b){

    // base case 
    // any number to the power 0 is 1 so return 1
    if(b==0){
        return 1;
    }
    // any number to the power 1 is the number itself, so return the number (a)
    if(b==1){
        return a;
    }

    int ans=calculatePower(a, b/2);

    // if b is even i.e. the power is even 
    if(b%2==0){
        return ans*ans;
    }
    else{
        // if b is odd 
        // i.e the power is odd
        return a*ans*ans;
    }
}

int main()
{
    int a, b;
    cout<<"Enter the number and the power"<<endl;
    cin>>a>>b;

    int ans=calculatePower(a, b);

    cout<<"The answer is : "<<ans<<endl;

    return 0;
}