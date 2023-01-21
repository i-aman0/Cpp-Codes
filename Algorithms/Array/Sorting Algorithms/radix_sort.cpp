#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

// Approach
// 1. Create iteration on every digit
// 2. Apply sorting on every 

int digits(int n){
    int digit = 0;
    while(n){
        digit++;
        n/=10;
    }
    return digit;
}

int get_pv(int a, int p){
    return (a/int(pow(10,p)))%10;
}

void pv_normal_sort(vector<int> &arr, int p){
    // auto cust_comp = [&](int a, int b){return a<b;};

    sort(
        arr.begin(), 
        arr.end(), 
        [&](int a, int b){
            return get_pv(a,p)<get_pv(b,p);
        }
    );
}

void pvBucketSort(vector<int> &arr, int p){

}

void radixSort(vector<int> &arr){
    cout << "Applying Radix Sort"<<endl;

    int maxNum = *max_element(arr.begin(), arr.end()); // max_element returns the pointer to the max number so use * to get the value 

    for(int p = 0; p < digits(maxNum); p++){
        pv_normal_sort(arr, p);
    }
}

void display(vector<int> &arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr;
    arr.push_back(1000);
    arr.push_back(99);
    arr.push_back(42);
    arr.push_back(7089);
    arr.push_back(6);
    arr.push_back(1132);
    arr.push_back(489);
    arr.push_back(7);
    arr.push_back(77);

    display(arr);
    return 0;
}