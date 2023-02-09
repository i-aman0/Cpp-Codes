#include<iostream>
#include<vector>
using namespace std;


// On each day, you may decide to buy and/or sell the stock. 
// You can only hold at most one share of the stock at any time.
// However, you can buy it then immediately sell it on the same day
// or sell and then buy on the same day


// if buyAllowed = 1, buying of the stock is allowed and you can buy or skip the stock
// if buyAllowed = 0, buying of the stock is not allowed and you can sell or skip the stock
int solve(vector<int> &nums, int index, int buyAllowed, vector<vector<int>> &dp){
    if(index == nums.size()){
        return 0;
    }

    if(dp[index][buyAllowed] != -1){
        return dp[index][buyAllowed];
    }

    int profit = 0;

    if(buyAllowed){
        int buyStock = -nums[index] + solve(nums, index + 1, 0, dp);
        int skipStock = 0 + solve(nums, index + 1, 1, dp);
        profit  = max(buyStock, skipStock);
    }
    else{
        int sellStock = nums[index] + solve(nums, index + 1, 1, dp);
        int skipStock = 0 + solve(nums, index + 1, 0, dp);
        profit = max(sellStock, skipStock);
    }

    return dp[index][buyAllowed] = profit;
}

int maxProfit(vector<int> &nums){
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int> (2, -1));
    return solve(nums, 0, 1, dp);
}

int main()
{
    vector<int> nums = {7,1,5,3,6,4};
    cout << "The maximum profit that can be obtained is : " << maxProfit(nums) << endl;
    return 0;
}