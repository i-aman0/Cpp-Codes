#include<iostream>
using namespace std;

bool isSorted(int* arr, int size){
    // base case
    // an array of size 0 or 1 is always sorted
    if(size==0 || size==1){
        return true;
    }

    // checking if first and second element of the array are not sorted
    // if not return false
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool ans=isSorted(arr+1, size-1);
        return ans;
    }
}

int sumOfArray(int arr[], int size){

    if(size==0){
        return 0;
    }

    if(size==1){
        return arr[0];
    }

    int sum=arr[0]+sumOfArray(arr+1, size-1); 
    return sum;

}

int main()
{
    int arr[]={1,2,2,4,5};
    int size=5;

    bool ans=isSorted(arr, size);
    if(ans){
        cout<<"The array is sorted"<<endl;
    }
    else{
        cout<<"The array is not sorted"<<endl;
    }

    int sum=sumOfArray(arr, size);
    cout<<"The sum of array is : "<<sum<<endl;

    return 0;
}