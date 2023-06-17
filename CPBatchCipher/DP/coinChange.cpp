#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

#define DP unordered_map<int, unordered_map<int, int> > 

bool findKey(DP &dp, int key1, int key2){
    return dp.find(key1) != dp.end() && dp[key1].find(key2) != dp[key1].end();
}

int coinChange(vector<int> &coins, int index, int sum, DP &dp){
    if(sum == 0){
        return 1;
    }

    if(sum < 0){
        return 0;
    }

    if(index < 0){
        return 0;
    }

    if(findKey(dp, index, sum)){
        return dp[index][sum];
    }

    int coinTaken = coinChange(coins, index, sum - coins[index], dp);
    int coinNotTaken = coinChange(coins, index - 1, sum, dp);

    return dp[index][sum] = coinTaken + coinNotTaken;
}

int main()
{
    vector<int> coins = {1, 2, 5, 10};
    DP dp;
    int sum = 7;

    cout << "Sum = " << sum << " : " << coinChange(coins, coins.size() - 1, sum, dp) << endl;
    return 0;
}