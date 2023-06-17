#include<iostream>
#include<vector>
using namespace std;

// Given an array prices where prices[i] is the price of the stock on ith day 
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Only one transaction is allowed  


// Extra space is being used 

// int maxProfit(vector<int> &nums){
//     int n = nums.size();
//     vector<int> dp(n);
//     dp[0] = 0;

//     int minimum = nums[0];

//     for(int i = 1; i < n; i++){
//         // Case - 1 
//         // Igonre the stock at ith index and continue with the profit at (i-1)th index
//         int c1 = dp[i - 1];

//         // Case - 2
//         // Sell the stock at ith index and purchase at minimum stock prior to i (i.e. 0 to i - 1)
//         int c2 = nums[i] - minimum;

//         dp[i] = max(c1, c2);

//         minimum = min(minimum, nums[i]);
//     }

//     return dp[n - 1];
// }



// NO extra space is used 
int maxProfit(vector<int> &nums){
    int n = nums.size();
    int minimum = nums[0];
    int profit = 0;

    for(int i = 1; i < n; i++){
        int diff = nums[i] - minimum;
        profit = max(profit, diff);

        minimum = min(minimum, nums[i]);
    }

    return profit;
}

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    cout << "The maximum profit that can be earned is : " << maxProfit(prices) << endl;
    return 0;
}