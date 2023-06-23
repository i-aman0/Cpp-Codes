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

void build(ll node, ll start, ll end, vector<ll> &v, vector<ll> &sgtree){
    if(start == end){ // leaf node
        sgtree[node] = v[start];
        return;
    }

    ll mid = (start + end) / 2;
    build(2 * node + 1, start, mid, v, sgtree);
    build(2 * node + 2, mid + 1, end, v, sgtree);
    sgtree[node] = sgtree[2 * node + 1] + sgtree[2 * node + 2];
}

void update(ll node, ll start, ll end, vector<ll> &sgtree, ll index, ll val){
    if(index > end || index < start){
        return;
    }
    
    sgtree[node] += val;

    if(start == end){
        return;
    }

    ll mid = (start + end) / 2;

    update(2*node+1, start, mid, sgtree, index, val);
    update(2*node+2, mid+1, end, sgtree, index, val);
}

ll getSum(ll node, ll start, ll end, vector<ll> &sgtree, ll qst, ll qend){
    if(qst > end || qend < start){
        return 0;
    }

    if(start >= qst && end  <= qend){
        return sgtree[node];
    }

    ll mid = (start + end ) / 2;
    return getSum(2*node+1, start, mid, sgtree, qst, qend) + getSum(2*node+2, mid + 1, end, sgtree, qst, qend);
}

int main(){
    // v();

    int n;
    cin >> n;

    vector<ll> arr(n);

    for(ll i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<ll> sgtree(4 * n + 1, 0);

    build(0, 0, n - 1, arr, sgtree); // 0 index node is the root node and it will store the data from 0 to n - 1 

    for(auto itr : sgtree){
        cout << itr << " ";
    }

    update(0, 0, n - 1, sgtree, 1, -3);

    cout << getSum(0, 0, n - 1, sgtree, 1, 6); // get sum from index 1 to 6
    
    return 0;
}