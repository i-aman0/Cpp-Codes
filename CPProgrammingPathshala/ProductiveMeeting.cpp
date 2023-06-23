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

// https://codeforces.com/problemset/problem/1579/D

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



int main(){
    // v();

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        priority_queue<pair<ll, ll> > pq;

        for(ll i = 0; i < n; i++){
            ll x;
            cin >> x;

            if(x) pq.push(make_pair(x, i + 1));
        }
        
        int count = 0;

        vector<pair<ll, ll> > ans;

        while(pq.size() > 1){
            pair<ll, ll> a = pq.top();
            pq.pop();
            pair<ll, ll> b = pq.top();
            pq.pop();

            ans.push_back(make_pair(a.second, b.second));
            a.first--;
            b.first--;

            if(a.first) pq.push(a);
            if(b.first) pq.push(b);

            count++;
        }

        // count will be equal to ans.size()
        cout << count << "\n";

        for(auto p : ans){
            cout << p.first << " " << p.second << "\n";
        }

    }
    return 0;
}