#include<iostream>
#include<vector>
using namespace std;

int solve(int n, vector<int> &days, vector<int> &costs, int index, vector<int> &dp){
    if(index >= n){
        return 0;
    }

    if(dp[index] != -1){
        return dp[index];
    }

    // 1 day pass
    int cost1 = costs[0] + solve(n, days, costs, index + 1, dp);

    // 7 days pass
    int i;
    for(i = index; i < n && days[i] < days[index] + 7; i++); // moving 7 days ahead 
    int cost2 = costs[1] + solve(n, days, costs, i, dp);


    // 30 days pass
    for(i = index; i < n && days[i] < days[index] + 30; i++); // moving 30 days ahead
    int cost3 = costs[2] + solve(n, days, costs, i, dp);

    return dp[index] = min(cost1, min(cost2, cost3));
}

int minCost(vector<int> &days, vector<int> &costs){
    int n = days.size();
    vector<int> dp(n + 1, -1);
    return solve(n, days, costs, 0, dp);
}

int main()
{
    vector<int> days = {1,4,6,7,8,20};
    vector<int> costs = {2,7,15};

    int res = minCost(days, costs);
    cout << "The minimum cost is : " << res << endl;
    return 0;
}