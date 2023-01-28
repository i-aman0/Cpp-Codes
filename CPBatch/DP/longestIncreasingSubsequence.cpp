#include<iostream>
#include<vector>
using namespace std;

int lengthOfLIS(vector<int> &nums){
    int n = nums.size();

    vector<int> dp(n, 1);

    for(int i = 1; i < n; i++){
        for(int j = i - 1; j >= 0; j--){
            if(nums[j] < nums[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int m = 0;

    for(int i = 0; i < n; i++){
        m = max(m, dp[i]);
    }

    return m;
}

int main()
{
    vector<int> arr = {10,9,2,5,3,7,101,18};

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    cout << "The length of longest increasing subsequence is : " << lengthOfLIS(arr) << endl;
    return 0;
}