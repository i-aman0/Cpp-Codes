#include <iostream>
#include <vector>
#include <cmath>
#include <ostream>
#include <list>
#include <map>
#include <algorithm>
#include <climits>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <iterator>
#include <set>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <queue>
#include <chrono>
#include <deque>
#include <string>
#include <unordered_map>
#include<assert.h>
#include <unordered_set>

#define ll long long
#define mod 1e9 + 7

using namespace std;

// void v(){
//     #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     #endif
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     srand((unsigned int)time(NULL));
// }

#define ll long long

using namespace std;


// https://codeforces.com/contest/265/problem/C


int main(){
    // v();

    string str;
    cin >> str;

    stack<ll> st;
    vector<ll> ans;
    int n = str.length();

    for(int i = 0; i < n; i++){
        if(str[i] == 'r'){
            ans.push_back(i + 1);
        }
        else{
            st.push(i + 1);
        }
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    for(auto num : ans){
        cout << num << "\n";
    }
    return 0;
}