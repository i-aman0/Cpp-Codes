#include<iostream>
#include<cmath>
using namespace std ;

int check(int num){
    int num2 = num;
    int sum = 0 ;
    while(num!=0){
        int num3 = num%10;
        num = num/10;
        sum = sum + pow(num3,3);
    }
    cout<<sum<<endl;
    if(sum == num2)
    {
        return 1;
    }
    
    return -1;
}

int main ()
{
    int num = 153;
    // cin>>num;
    cout<<check(num);
    return 0 ;
}