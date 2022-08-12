#include<stdio.h>
int main()
{
int a[5]={2,20,30,50,6};
int key,found=0,i;
printf("\nThe elements in an array are");

for(i=0;i<5;i++)
printf("\n%d",a[i]);

printf("\n enter the element to be searched");
scanf("%d",&key);

for(i=0;i<5;i++)
{
    if(key==a[i])
    {
    found=1;
    break;
    }
}
if (found==0)
printf("\n The element is not present in the array");
else
printf("\n The element is present at %d/t%d",i+1,a[i]);
return 0;
}
