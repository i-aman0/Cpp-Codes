// #include<iostream>
// #include<vector>
// #include<math.h>
// #include<set>
// #include<algorithm>
// using namespace std;

// int findMex(vector<int> nums){
//     sort(nums.begin(), nums.end());
//     int n = nums.size();
//     int ans = 0;
//     for (int i = 0; i < nums.size(); i++) {
//         if (nums[i] != ans) {
//             return ans;
//         }
//         ans++;
//     }

//     return ans + 1;
    
// }

// void mexAndMax(vector<int> &arr){
//     int n = arr.size();

//     int maxx = arr[0];
//     for(int i  = 0; i < n; i++){
//         if(arr[i] > maxx){
//             maxx = arr[i];
//         }
//     }

//     int mex = findMex(arr);

//     int a = ceil((maxx + mex)/2);

//     arr.push_back(a);
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while(t){
//         int n, k;
//         cin >> n >> k;

//         vector<int> arr(n);
//         for(int i  = 0; i < n; i++){
//             cin >> arr[i];
//         }

//         while(k){
//             mexAndMax(arr);
//             k--;
//         }

//         set<int> s;
//         for(int i = 0; i < arr.size(); i++){
//             s.insert(arr[i]);
//         }

//         cout << s.size() << endl;

//         t--;
//     }
//     return 0;
// }













#include<iostream>
#include <cstdio>
#include <set>

using namespace std;

int main(){
    
    long t; 
    cin >> t;
    while(t--){
        long n, k; 
        cin >> n >> k;
        long max(0), mex(0); 
        set<long> s;
        for(long p = 0; p < n; p++){
            long x; 
            cin >> x;
            s.insert(x);
            max = (max > x) ? max : x;
        }

        if(max == n - 1){
            cout << n + k << endl;
            continue;
        }
        for(long p = 0; p < 1e9 + 7; p++){
            if(!s.count(p)){
                mex = p;
                break;
            }
        }

        long u = (max + mex + 1) / 2;
        long add = (k > 0) * (1 - s.count(u));
        cout << s.size() + add << endl;
    }

}