#include<iostream>
using namespace std;

// two ways to solve : 
// 1. when dividing the array from the middle element into two halves, we do not divide the original array
//    instead we create 2 separate new arrays and copy the elements into them 
// 2. when dividing the array from the middle elemetn into two halves, 
//    we use the indexes and actually divide the arrays based on the value of indexes

void merge(int* arr, int start, int end){
    int mid=start+(end-start)/2;

    int len1=mid-start+1;
    int len2=end-mid;

    int* first=new int[len1];
    int* second=new int[len2];


    // start copying the element from the array to the new arrays formed 

    // copy the first half in the first array
    int k=start;  // k represents the index of main array
    for(int i=0; i<len1; i++){
        first[i]=arr[k];
        k++;
    }

    // copy the second half in the second array
    k=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[k];
        k++;
    }

    // merge two sorted arrays
    int index1=0;
    int index2=0;
    k=start;
    while(index1<len1 && index2<len2){
        if(first[index1] < second[index2]){
            arr[k]=first[index1];
            k++;
            index1++;
        }
        else{
            arr[k]=second[index2];
            k++;
            index2++;
        }
    }

    while(index1<len1){
        arr[k]=first[index1];
        k++;
        index1++;
    }

    while (index2<len2)
    {
        arr[k]=second[index2];
        k++;
        index2++;
    }
    

}

void mergeSort(int* arr, int start, int end){
    // base case 
    if(start>=end){
        return;
    }

    int mid=start+(end-start)/2;

    // sort the left part
    mergeSort(arr, start, mid);

    // sort right part 
    mergeSort(arr, mid+1, end);

    // merge the sorted parts
    merge(arr, start, end);
}

int main()
{
    int arr[]={3,9,5,4,6,2,8};

    // passing array, starting index and ending index of the array
    mergeSort(arr, 0, 6);

    cout<<"The sorted array is : "<<endl;
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}