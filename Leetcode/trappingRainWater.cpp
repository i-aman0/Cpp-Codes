#include<iostream>
#include<vector>
using namespace std;

int trapRainWater(vector<int> &nums){
    int n = nums.size();

    vector<int> left(n);
    vector<int> right(n);

    left[0] = nums[0];
    right[n - 1] = nums[n - 1];

    for(int i = 1; i < n; i++){
        left[i] = max(left[i - 1], nums[i]);
    }

    for(int i = n - 2; i >= 0; i--){
        right[i] = max(right[i + 2], nums[i]);
    }

    int ans = 0;

    for(int i = 1; i < n - 1; i++){
        int var = min(left[i - 1], right[i + 1]);

        if(var > nums[i]){
            ans += var - nums[i];
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "The amount of water that can be trapped is : " << trapRainWater(arr) << endl;
    return 0;
}