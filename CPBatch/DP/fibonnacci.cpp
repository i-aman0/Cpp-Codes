#include<iostream>
#include<unordered_map>
using namespace std;

int fibo(int n, unordered_map<int, int> &dp){
    if(n < 2){
        return 1;
    }

    // if the element is not already present in the map
    if(dp.find(n) == dp.end()){
        dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
    }
    
    return dp[n];
}

int main()
{
    unordered_map<int, int> dp;
    for(int i = 0; i < 100; i++){
        cout << i << " : " << fibo(i, dp) << endl;
    }
    return 0;
}