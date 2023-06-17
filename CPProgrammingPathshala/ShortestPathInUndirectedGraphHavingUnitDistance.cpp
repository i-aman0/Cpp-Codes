#include<iostream>
#include<stack>
#include<unordered_map>
#include<map>
#include<queue>

#define ll long long

using namespace std;

// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> ans(N, -1);
        queue<int> q;
        q.push(src);
        ans[src] = 0;
        vector<vector<int>> adj(N);
        
        for(auto itr : edges){
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }
        
         while(q.size())
        {
            queue<int> tempq;
            while(q.size())
            {
                int node=q.front();
                for(auto itr:adj[node])
                {
                    if(ans[itr]==-1)    
                    {
                        ans[itr]=ans[node]+1;
                        tempq.push(itr);
                    }
                }
                q.pop();
            }
            
            q=tempq;
        }
        return ans;
        
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}