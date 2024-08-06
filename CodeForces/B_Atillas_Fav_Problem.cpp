#include <bits/stdc++.h>

#define ll long long
#define mod 1e9 + 7

using namespace std;


int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        string str;
        cin >> str;

        int maxPos = INT_MIN;

        for(auto ch : str){
            int currPos = ch - 'a' + 1;
            maxPos = max(maxPos, currPos);
        }

        cout << maxPos << endl;
    }

    return 0;
}