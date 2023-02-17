#include<iostream>
#include<vector>
using namespace std;

// given an array, return all the unique combinations of the numbers from array such that their sum is equal to 0

vector<vector<int>> threeSum(vector<int> nums){
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for(int i = 0; i < n - 2; i++){
        if(i == 0 || (i > 0 && nums[i] != nums[i - 1])){
            int s = i + 1;
            int e = n - 1;
            int target = 0 - nums[i];

            while(s < e){
                if(nums[e] + nums[s] == target){
                    ans.push_back({nums[i], nums[s], nums[e]});

                    while(s < e && nums[s] == nums[s + 1]){
                        s++;
                    }

                    while(s < e && nums[e] == nums[e - 1]){
                        e--;
                    }

                    s++;
                    e--;
                }
                else if(nums[s] + nums[e] < target){
                    s++;
                }
                else{
                    e--;
                }
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {-1,0,1,2,-1,-4};

    vector<vector<int>> ans = threeSum(arr);

    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}