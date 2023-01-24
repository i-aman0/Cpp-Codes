// given two strings, find the minimum number of operations to make the two strings equal
// the operations that are permissibe are insert, remove and replace 

#include<iostream>
#include<unordered_map>
using namespace std;

// we will solve the question by assuming that we make all the changes to the first string 
// we can also make the changes to the second string, it does not make any difference 

#define DP unordered_map<int, unordered_map<int, int> >

bool findKey(DP &dp, int key1, int key2){
    return dp.find(key1) != dp.end() && dp[key1].find(key2) != dp[key1].end();
}

int editDistance(string &first, int firstIndex, string &second, int secondIndex, DP &dp){
    
    // if the first string is finished or the first string is empty
    if(firstIndex == first.size()){
        return second.size() - secondIndex;
    }

    // if the second string is empty
    if(secondIndex == second.size()){
        return first.size() - firstIndex;
    }

    // applied dp
    // check if the value already exist in the map, return it
    if(findKey(dp, firstIndex, secondIndex)){
        return dp[firstIndex][secondIndex];
    }

    // if the charcters in both the strings are same 
    if(first[firstIndex] == second[secondIndex]){
        return dp[firstIndex][secondIndex] = editDistance(first, firstIndex+1, second, secondIndex+1, dp);
    }

    // cost of removing the character from the first string 
    int removeOperationCost = editDistance(first, firstIndex+1, second, secondIndex, dp);

    //cost of inserting the character into first string
    int insertOperationCost = editDistance(first, firstIndex, second, secondIndex+1, dp);

    // cost of replacing the characeter from the first string
    int replaceOperationCost = editDistance(first, firstIndex+1, second, secondIndex+1, dp);

    return dp[firstIndex][secondIndex] = 1+min(removeOperationCost, min(insertOperationCost, replaceOperationCost)); 
    // returning the minimum of all the above costs
}

int main()
{
    string me = "KARTAVYA";
    string crush = "KRITIKA";

    DP dp;

    cout << editDistance(me, 0, crush, 0, dp) << endl;
    return 0;
}