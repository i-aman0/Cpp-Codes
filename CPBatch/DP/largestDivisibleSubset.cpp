#include<iostream>
#include<vector>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums){
    int n = nums.size();

    vector<pair<int, int>> dp(n);

    for(int i = 0; i < n; i++){
        dp[i] = {1, i};
    }

    sort(nums.begin(), nums.end());

    for(int i = 1; i < n; i++){
        int index = i;

        for(int j = i -1; j >= 0; j--){
            if(nums[i] % nums[j] == 0){
                if(dp[j].first + 1 > dp[i].first){
                    dp[i].first = dp[j].first + 1;

                    index = j;
                }
            }
        }

        dp[i].second = index;
    }

    int index = -1;
    int mx = 0;

    for(int i = 0; i < n; i++){
        if(mx < dp[i].first){
            mx = dp[i].first;

            index = i;
        }
    }

    vector<int> ans;

    while(dp[index].second != index){
        ans.push_back(nums[index]);
        index = dp[index].second;
    }

    ans.push_back(nums[index]);

    return ans;

}

int main()
{
    vector<int> arr = {1, 2, 4, 8};

    vector<int> res = largestDivisibleSubset(arr);

    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }

    cout << endl;
    return 0;
}