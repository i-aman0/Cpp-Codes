#include<iostream>
using namespace std;

void sayDigit(int n){
    string arr[10]={"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    if(n==0){
        return;
    }

    int digit=n%10;
    sayDigit(n/10);

    cout<<arr[digit]<<endl;
}

int main()
{
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    sayDigit(n);

    return 0;
}