#include <bits/stdc++.h>

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

using namespace std;

#define ll long long
class Solution
{
public:
    int minimumJumps(vector<int> &forbidden, int a, int b, int x)
    {
        ll n = forbidden.size();
        queue<pair<ll, ll>> q;
        vector<ll> dp(10001, INT_MAX);
        for (auto itr : forbidden)
        {
            dp[itr] = -1;
        }
        q.push({0, 1});
        dp[0] = 0;
        while (q.size())
        {
            ll node = q.front().first;
            // cout<<node<<"\n";
            ll can = q.front().second;
            q.pop();

            if (can && (node - b >= 0))
            {
                if (dp[node - b] > dp[node] + 1)
                {
                    dp[node - b] = dp[node] + 1;
                    q.push({node - b, 0});
                }
            }
            if (node + a <= 10000)
            {
                if (dp[node + a] > dp[node] + 1)
                {
                    dp[node + a] = dp[node] + 1;
                    q.push({node + a, 1});
                }
            }
        }
        if (dp[x] == INT_MAX)
        {
            return -1;
        }
        return dp[x];
    }
};

int main()
{
    v();

    return 0;
}