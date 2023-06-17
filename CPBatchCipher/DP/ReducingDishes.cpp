#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.com/problems/reducing-dishes/description/

int solve(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp){
    if(index >= satisfaction.size()){
        return 0;
    }

    if(dp[index][time] != -1){
        return dp[index][time];
    }

    int include = satisfaction[index] * (time + 1) + solve(satisfaction, index + 1, time + 1, dp);
    int exclude = 0 + solve(satisfaction, index + 1, time, dp);

    return dp[index][time] = max(include, exclude);
}

int maxSatisfaction(vector<int> &satisfaction){
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());

    vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));

    return solve(satisfaction, 0, 0, dp);

}

int main()
{
    vector<int> satisfaction = {-1,-8,0,5,-9};
    int res = maxSatisfaction(satisfaction);

    cout << "The maximum satisfaction is : " << res << endl;
    return 0;
}