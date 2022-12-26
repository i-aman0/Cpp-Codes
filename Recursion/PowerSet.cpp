
// given a set containing integers, return the power set of that set i.e. the set of all the subsets

#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int> > &ans){
    // base case
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }

    // exclude the selected element
    solve(nums, output, index+1, ans);

    // include the selected element
    int element=nums[index];
    output.push_back(element);
    solve(nums, output, index+1, ans);
}

vector<vector<int> > subset(vector<int> nums){
    vector<vector<int> > ans;
    vector<int> output;
    int index=0;

    solve(nums, output, index, ans);
    return ans;
}

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    vector<vector<int> > ans=subset(nums);

    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}