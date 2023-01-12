// given an array of integers, return all the permutations of the array
// e.g. arr={1,2,3}
// O/P ={{1,2,3}, {1,3,2}, {2,1,3}, {2,3,1}, {3,1,2}, {3,2,1}}
// total number of permutations = n!

#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> nums, vector<vector<int> > &ans, int index){
    // base case
    if(index >= nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int j=index; j<nums.size(); j++){
        swap(nums[index], nums[j]);
        solve(nums, ans, index+1);
        swap(nums[index], nums[j]); // backtracking i.e. swapping the same elements again to maintain the order of the original array of the numbers
    }
}

vector<vector<int> > permutations(vector<int> nums){
    vector<vector<int> > ans;
    int index=0;

    solve(nums, ans, index);
    return ans;
}

int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    vector<vector<int> > ans=permutations(arr);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}