#include <iostream>
#include <bits/stdc++.h>
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

// https://codeforces.com/problemset/problem/1167/C

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


ll getParent(ll node, vector<ll> &parent){
    if(node == parent[node]){
        return node;
    }

    return parent[node] = getParent(parent[node], parent);
}

int main(){
    // v();

    ll n, m;
    cin >> n >> m;

    vector<ll> parent(n + 5, 0);
    vector<ll> size(n + 5, 0);
    for(int i = 0; i < n; i++){
        parent[i] = i;
        size[i] = 1;
    }

    for(ll i = 0; i < m; i++){
        ll k;
        cin >> k;

        for(ll j = 0; j < k; j++){
            ll prev;
            ll next;

            if(j == 0){
                cin >> prev;
                continue;
            }

            cin >> next;

            ll parPrev = getParent(prev, parent);
            ll parNext = getParent(next, parent);

            if(parPrev == parNext){
                continue;
            }

            if(size[parPrev] > size[parNext]){
                parent[parNext] = parPrev;
                size[parPrev] += size[parNext];
            }
            else{
                parent[parPrev] = parNext;
                size[parNext] += size[parPrev];
            }

            prev = next;

        }
    }

    for(ll i = 1; i <= n; i++){
        cout<<size[getParent(i,parent)]<<" ";
    }

}