#include <iostream>
#include <vector>
#include <cmath>
#include<assert.h>
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
#include <deque>
#include <set>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <queue>
#include <chrono>
#include <deque>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("Ofast")
#define ll long long
#define modd 998244353
#define mod 1000000007
#define cbit __builtin_popcountll
#define pl pair<long, long>
#define pqp priority_queue<pl>
#define mkp make_pair
#define vl vector<ll>
#define vvl vector<vl >
#define pb push_back
#define inf 1000000000000000000
#define ld long double
#define all(v) v.begin(), v.end()

ll pr(ll upper)
{
    ll i;
    ll lower=1;
    ll num = (rand() % (upper - lower + 1)) + lower;
    return num;
}



int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("input.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand((unsigned int)time(NULL));
    ll t=1;
    // t = pr(10);
    // cout<<t<<"\n";
    while (t--)
    {
        ll n;
        n=100+pr(1000);
        // n*=2;
        cout<<n<<"\n";
        ll k=1+pr(5);
        cout<<k<<"\n";
        for(ll i=0;i<n;i++)
        {
            cout<<pr(1000000000)<<" ";
        }
        cout<<"\n";
        // ll x=2;
        // cout<<x<<"\n";
        
    }
}