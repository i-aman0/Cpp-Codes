bool findKey(DP &dp, int key1, int key2){
    return dp.find(key1) != dp.end() && dp[key1].find(key2) != dp[key1].end();
}