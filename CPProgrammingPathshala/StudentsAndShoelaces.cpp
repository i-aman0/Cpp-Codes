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
#include <assert.h>
#include <unordered_set>

#define ll long long
#define mod 1e9 + 7

using namespace std;

void v()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand((unsigned int)time(NULL));
}

#define ll long long

using namespace std;

// https://codeforces.com/contest/129/problem/B

int main()
{
    v();

    int n;
    int m;
    cin >> n >> m;
    vector<set<ll> > graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].insert(y);
        graph[y].insert(x);
    }
    ll ans = 0;
    queue<ll> q;
    for (ll i = 1; i <= n; i++)
    {
        if (graph[i].size() == 1)
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        ans++;
        while (q.size())
        {
            ll node = q.front();
            for (auto itr : graph[node])
            {
                graph[itr].erase(node);
            }
            graph[node].clear();
            q.pop();
        }
        for (ll i = 1; i <= n; i++)
        {
            if (graph[i].size() == 1)
            {
                q.push(i);
            }
        }
    }
    cout << ans << "\n";

    return 0;
}