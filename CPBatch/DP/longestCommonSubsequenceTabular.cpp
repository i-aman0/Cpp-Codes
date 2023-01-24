#include<iostream>
#include<vector>
using namespace std;

int lcs(string &first, string &second){
    vector<vector<int> > dp(first.size() + 1, vector<int>(second.size() + 1, 0));

    for(int i = 1; i <= first.size(); i++){
        for(int j = 1; j <= second.size(); j++){
            if(first[i - 1] == second[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
    }

    return dp.back().back();
}

int main()
{
    string str1 = "KARTAVYA";
    string str2 = "KRITIKA";

    cout << lcs(str1, str2) << endl;
    return 0;
}