#include<stdio.h>

int binary_search(int arr[], int n, int item)
{
    int low=0;
    int high=n-1;
    int mid;
    while(low<=high) //i.e. keep searching until low and high converge
    {
        mid=(low+high)/2;
        if(arr[mid]==item)
        {
            return mid;
        }
        if(arr[mid]<item)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }

    }
    return -1;
}

int main()
{
    int n;
    printf("\nEnter the number of elements in the array");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter the elements of array");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int item;
    printf("\nEnter the item to be searched");
    scanf("%d",&item);
    int index=binary_search(arr,n,item);
    
    if(index==-1)
    {
        printf("element %d is not found",item);
    }
    else
    {
        printf("Element %d is present at index %d",item,index);
    }
    
}