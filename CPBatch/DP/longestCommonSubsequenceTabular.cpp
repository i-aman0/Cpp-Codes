#include<iostream>
#include<vector>
using namespace std;


// returns the length of longest common subsequence
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

// returns the longest common subsequence 
string getLCS(string &first, string &second){
    vector<vector<int>> dp(first.size() + 1, vector<int>(second.size() + 1, 0));

    // create the table as above
    for(int i = 1; i < first.size(); i++){
        for(int j = 1; j < second.size(); j++){
            if(first[i - 1] == second[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], max(dp[i - 1][j - 1], dp[i][j - 1]));
            }
        }
    }


    // to print the LCS, we traverse the matrix created above from last index and check if the values of both indexes is equal, we store the value
    // otherwise, move up to the greater of the left and top values
    string ans = "";
    int i = first.size(), j = second.size();

    while(i > 0 && j > 0){
        if(first[i - 1] == second[j - 1]){
            ans.push_back(first[i - 1]);
            i--;
            j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]){
            i--;
        }
        else{
            j--;
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string str1 = "KARTAVYA";
    string str2 = "KRITIKA";

    cout << endl;
    cout << "The longest common subsequence is : " << getLCS(str1, str2) << " and the length of the longest common subsequence is : " << lcs(str1, str2) << endl << endl;
    return 0;
}