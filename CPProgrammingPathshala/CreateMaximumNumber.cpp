#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> getvector(vector<int>& nums,int sz)
    {
        stack<int> st;
        int len=nums.size();
        
        for(int i=0;i<nums.size();i++)
        {
            if(st.size()==0||st.top()>=nums[i])
            {
                st.push(nums[i]);
            }
            else if(len>sz){
                st.pop();
                len--;
                i--;
            }
            else{
                st.push(nums[i]);
            }
        }
        vector<int> ans;
        while(st.size())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        while(ans.size()>sz)
        {
            ans.pop_back();
        }
        return ans;
    }
    
    
    vector<int> merge_vector(vector<int>&a , vector<int>& b)
    {
        vector<int> ans;
        int sta=0;
        int stb=0;
        while(sta<a.size()||stb<b.size())
        {
            if(sta==a.size())
            {
                ans.push_back(b[stb]);
                stb++;
            }
            else if(stb==b.size())
            {
                ans.push_back(a[sta]);
                sta++;
            }
            else if(a[sta]<b[stb])
            {
                ans.push_back(b[stb]);
                stb++;
            }
            else if(a[sta]>b[stb])
            {
                ans.push_back(a[sta]);
                sta++;
            }
            else{
                int taken=0;
                for(int i=0;i<a.size();i++)
                {
                    if(i+sta==a.size()||i+stb==b.size())
                    {
                        if(i+sta==a.size())
                        {
                            taken=1;
                        }
                        break;
                    }
                    else if(a[sta+i]>b[stb+i])
                    {
                        break;
                    }
                    else if(a[sta+i]<b[stb+i])
                    {
                        taken=1;
                        break;
                    }
                }
                if(taken==0)
                {
                    ans.push_back(a[sta]);
                    sta++;
                }
                else{
                    ans.push_back(b[stb]);
                    stb++;
                }
            }
        }
        return ans;
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        // return merge_vector(nums1,nums2);
        vector<int> ans(k,0);
        for(int i=0;i<=k;i++)
        {
            if(nums1.size()<i||nums2.size()<k-i)
            {
                continue;
            }
            vector<int> b=getvector(nums1,i);
            vector<int> a=getvector(nums2,k-i);
            
            vector<int> tempans = merge_vector(a,b);
            // for(auto itr:tempans)
            // {
            //     cout<<itr<<" ";
            // }
            // cout<<"\n";
            for(int j=0;j<k;j++)
            {
                if(tempans[j]>ans[j])
                {
                    ans=tempans;
                    break;
                }
                else if(ans[j]>tempans[j])
                {
                    break;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> arr = {3,4,6,5};
    vector<int> arr2 = {9,1,2,5,8,3};
    int k = 5;

    vector<int> ans = s.maxNumber(arr, arr2, k);

    for(auto num : ans){
        cout << num << endl;
    }
}