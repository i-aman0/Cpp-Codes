#include<iostream>
using namespace std;

void sortArray(int* arr, int size){
    // base case --> array already sorted
    if(size==0 || size==1){
        return;
    }

    // 1 case solve kr lo, rest will be handled by recursion
    // puts the largest element at the end of array 
    // again when second recursive call happens, puts the second largest element at the second last position in the array
    for(int i=0; i<size-1; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }
    
    // recursive call for the rest of array excluding the recently sorted element
    sortArray(arr, size-1);
}

int main()
{
    int arr[]={4,3,6,2,9,5,4};
    int size=7;

    sortArray(arr, size);

    cout<<"The sorted array is : "<<endl;
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }   
    cout<<endl;
    return 0;
}