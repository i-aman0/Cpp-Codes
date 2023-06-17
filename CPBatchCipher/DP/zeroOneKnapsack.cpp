#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

#define DP unordered_map<int, unordered_map<int, int> >

class Item{
    public: 
    int weight;
    int profit;
    bool isSelected;

    Item(int weight, int profit){
        this -> weight = weight;
        this -> profit = profit;
        isSelected = false;
    }
};

int knapsack(int weightLeft, int item, vector<Item*> &items, DP &dp){
    if(item == -1 || weightLeft == 0){
        return 0;
    }

    if(dp.find(weightLeft) != dp.end() && dp[weightLeft].find(item) != dp[weightLeft].end()){
        return dp[weightLeft][item];
    }

    Item* it = items[item];

    if(it -> weight > weightLeft){
        return dp[weightLeft][item] = knapsack(weightLeft, item - 1, items, dp);
    }

    int case1Profit = it -> profit + knapsack(weightLeft - it -> weight, item - 1, items, dp);

    int case2Profit = knapsack(weightLeft, item - 1, items, dp);

    return dp[weightLeft][item] = max(case1Profit, case2Profit);
}

int main()
{
    vector<Item*> items = {
        new Item(50, 100),
        new Item(20, 39),
        new Item(20, 39),
        new Item(15, 29)
    };
    
    DP dp;

    cout << "Maximum profit you can make is : " << knapsack(60, 3, items, dp) << endl;
    return 0;
}