#include<iostream>
#include<unordered_map>
using namespace std;

#define DP unordered_map<int, unordered_map<int, int> >

bool findKey(DP &dp, int key1, int key2){
    return dp.find(key1) != dp.end() && dp[key1].find(key2) != dp[key1].end();
}

int editDistance(string &first, int firstIndex, string &second, int secondIndex, DP &dp){
    if(firstIndex == first.size()){
        return second.size() - secondIndex;
    }

    if(secondIndex == second.size()){
        return first.size() - firstIndex;
    }

    if(findKey(dp, firstIndex, secondIndex)){
        return dp[firstIndex][secondIndex];
    }

    if(first[firstIndex] == second[secondIndex]){
        return dp[firstIndex][secondIndex] = editDistance(first, firstIndex+1, second, secondIndex+1, dp);
    }

    int removeOperationCost = editDistance(first, firstIndex+1, second, secondIndex, dp);
    int insertOperationCost = editDistance(first, firstIndex, second, secondIndex+1, dp);
    int replaceOperationCost = editDistance(first, firstIndex+1, second, secondIndex+1, dp);

    return dp[firstIndex][secondIndex] = 1+min(removeOperationCost, min(insertOperationCost, replaceOperationCost));
}

int main()
{
    string me = "KARTAVYA";
    string crush = "KRITIKA";

    DP dp;

    cout << editDistance(me, 0, crush, 0, dp) << endl;
    return 0;
}