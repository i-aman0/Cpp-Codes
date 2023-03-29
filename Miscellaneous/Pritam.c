#include<stdio.h>
#include<math.h>
#include<stdbool.h>
int isPrime(int n)
{
    bool flag=true;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            flag=false;
            break;
        }
    }
    if(flag==false)
    {
        return -1;
    }
    else 
    {
        return n;
    }
}
int main()
{
    int n;
    
    printf("Enter the number");
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        int ans=isPrime(i);
        if(ans!=-1)
        {
            printf("%d\t",ans);
        }
    }
}