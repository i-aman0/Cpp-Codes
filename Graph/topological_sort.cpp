#include <bits/stdc++.h>

#define ll long long
#define mod 1e9 + 7

using namespace std;

void v(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand((unsigned int)time(NULL));
}

using namespace std;

void dfs(int node, vector<int> &visited, vector<vector<int>> &adj, stack<int> &st){
    visited[node] = 1;

    for(auto it : adj[node]){
        if(!visited[it]){
            dfs(it, visited, adj, st);
        }
    }

    st.push(node);
}

vector<int> topoSort(int V, vector<vector<int>> &adj){

    vector<int> visited(V, 0);
    stack<int> st;

    for(int i = 0; i < V; i++){
        if(!visited[i]){
            dfs(i, visited, adj, st);
        }
    }

    vector<int> ans;

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

int main(){
    //v();

    int N, E;
    
    cin >> E >> N;

    int u, v;
    vector<vector<int>> adj;

    for(int i = 0; i < E; i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> res = topoSort(N, adj);

    for(auto it : res){
        cout << it << " , ";
    }
    
    return 0;
}