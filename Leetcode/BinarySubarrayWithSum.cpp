#include<iostream>
#include<vector>
using namespace std;

// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
// https://leetcode.com/problems/binary-subarrays-with-sum/description/



// the idea is to count all the subarrays with sum upto goal and count all the subarrays with sum upto goal - 1 separately
// calculate the difference of the two and we will get the count of all the subarrays with sum == goal

int solve(vector<int> &nums, int goal){
    if(goal < 0){
        return 0;
    }

    int i = 0; // start of the window 
    int n = nums.size();
    int sum = 0;
    int count = 0;

    // j represents end of the window 
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