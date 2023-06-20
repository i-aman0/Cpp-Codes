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

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0), ans;
        for (auto &e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 1)
                q.push(i), indegree[i]--;
        }
        while (!q.empty())
        {
            int s = q.size();
            ans.clear();
            for (int i = 0; i < s; i++)
            {
                int curr = q.front();
                q.pop();
                ans.push_back(curr);
                for (auto child : graph[curr])
                {
                    indegree[child]--;
                    if (indegree[child] == 1)
                        q.push(child);
                }
            }
        }
        if (n == 1)
            ans.push_back(0);
        return ans;
    }
};

int main()
{
    v();

    return 0;
}