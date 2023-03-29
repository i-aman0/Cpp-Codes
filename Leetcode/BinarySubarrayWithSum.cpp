#include<iostream>
#include<vector>
using namespace std;

// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
// https://leetcode.com/problems/binary-subarrays-with-sum/description/

int solve(vector<int> &nums, int goal){
    if(goal < 0){
        return 0;
    }

    int i = 0;
    int n = nums.size();
    int sum = 0;
    int count = 0;

    for(int j = 0; j < n; j++){
        sum += nums[j];

        while(sum > goal){
            sum -= nums[i];
            i++;
        }

        count += j - i + 1;
    }

    return count;
}

int maxNum(vector<int> &nums, int goal){
    return solve(nums, goal) - solve(nums, goal - 1);
}

int main()
{
    vector<int> nums = {1,0,1,0,1};
    int res = maxNum(nums, 2);
    cout << res << endl;
    return 0;
}