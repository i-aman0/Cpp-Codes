#include<iostream>
#include<vector>
using namespace std;


// Method 1. 
// rotate the array once and then call the rotate function k times

// void rotateRight(vector<int> &nums){
//     int v = nums.back();

//     for(int i = 0; i < nums.size() - 2; i--){
//         nums[i+1] = nums[i];
//     }

//     nums[0] = v;
// }

// void rotate(vector<int> &nums, int k){
//     int n = nums.size();
//     k = k % n;

//     for(int i = 0; i < k; i++){
//         rotateRight(nums);
//     }
// }

//  Method 2.
// SC - O(n)
// void rotate(vector<int>& nums, int k) {
//     vector<int> ans;

//     int n = nums.size();
//     k = k % n;

//     for(int i = n-k; i < n; i++){
//         ans.push_back(nums[i]);
//     }

//     for(int i = 0; i < n-k; i++){
//         ans.push_back(nums[i]);
//     }

//     for(int i = 0; i < n; i++){
//         nums[i] = ans[i];
//     }
// }



// Method 3. 
// Reverse the entire array and then reverse the first k elements and then n-k elements

void reverse(vector<int> &nums, int start, int end){
    while (start < end){
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

void rotate(vector<int> &nums, int k){
    
    int n = nums.size();
    k = k % n;
    
    // first reverse the entire array 
    reverse(nums, 0, n-1);

    // then reverse the first k elements
    reverse(nums, 0, k-1);

    // now reverse the last n-k elements
    reverse(nums, k, n-1);
}



int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);

    int k=3;

    rotate(arr, k);

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    return 0;
}