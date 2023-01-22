#include<iostream>
#include<vector>
using namespace std;

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        ret.push_back(-1);
        ret.push_back(-1);
        if(nums.size()==0)
        {
            return ret;
        }
        
        
        else
        {
            int low=0;
            int high=nums.size()-1;
            int mid;
            while(low<=high)
            {
                mid=(low+high)/2;
                if(nums[mid]==target && nums[mid-1]<target)
                {
                    ret[0]=mid;
                }
                else if(nums[mid]<target)
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
            while(low<=high)
            {
                mid=(low+high)/2;
                if(nums[mid]==target)
                {
                    ret[1]=mid;
                }
                else if(nums[mid]<target)
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
            
        }
        

        for(int i=0;i<ret.size();i++)
        {
            cout<<ret[i]<<" ";
        }

        return ret;
        
    }

int main()
{
    vector<int> v1;
    v1.push_back(5);
    v1.push_back(7);
    v1.push_back(7);
    v1.push_back(8);
    v1.push_back(8);
    v1.push_back(10);
    
    vector<int> ans = searchRange(v1,8);

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " " ;
    }

    return 0;
}