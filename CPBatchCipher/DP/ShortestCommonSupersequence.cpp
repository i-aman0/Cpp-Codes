#include<iostream>
#include<vector>
using namespace std;

// the idea is to find the length of longest common subsequence (lcs)
// the length of the shortest common supersequence is st1.length + str2.length - length(lcs)
// i.e. for shortest common supersequence we need to add the lcs for one time only to minimize its length

string supersequence(string str1, string str2){
    int n = str1.length();
    int m = str2.length();
    string ans = "";
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(str1[i - 1] == str2[j - 1]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int i = n;
    int j = m;

    while(i > 0 && j > 0){
        if(str1[i - 1] == str2[j - 1]){
            ans.push_back(str1[i - 1]);
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]){
            ans.push_back(str1[i - 1]);
            i--;
        }
        else{
            ans.push_back(str2[j - 1]);
            j--;
        }
    }

    while(i > 0){
        ans.push_back(str1[i - 1]);
        i--;
    }

    while(j > 0){
        ans.push_back(str2[j - 1]);
        j--;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string str1 = "brute";
    string str2 = "groot";

    string res = supersequence(str1, str2);
    cout << "The shortest common supersequence is : " << res << endl;
    return 0;
}