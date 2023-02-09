#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<int>> adj;

    // isDirected tells whether the graph is directed or not 
    // true if directed and false otherwise
    void addEdge(int u, int v, bool isDirected){
        adj[u].push_back(v);

        // if the graph is not directed, then add the reverse edge as well
        if(!isDirected){
            adj[v].push_back(u);
        }
    }

    void printGraph(){
        for(auto i : adj){
            cout << i.first << " -> { " ;
            for(auto j : i.second){
                cout << j << ", ";
            }

            cout << "}" << endl;

        }
    }

    void bfs(vector<int> &ans, int node, unordered_map<int, bool> &visited){
        queue<int> q;
        q.push(node);

        visited[node] = 1;

        while(!q.empty()){
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for(auto i : adj[frontNode]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = 1;

                }
            }
        }
    }

    vector<int> BFS(int n){
        vector<int> ans;
        unordered_map<int, bool> visited;

        for(int i = 1; i <= n; i++){
            bfs(ans, i, visited);
        }

        return ans;
    }
    
};

int main()
{
    int n;
    cout << "Enter the number of nodes : ";
    cin >> n;

    int m;
    cout << "Enter the number of edges : ";
    cin >> m;

    Graph g;

    cout << "Enter the pairs of adjacent nodes : ";
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;

        g.addEdge(u, v, false);
    }

    g.printGraph();
    vector<int> result = g.BFS(n);
    for(int i = 0; i < n; i++){
        cout << result[i] << " ";
    }

    cout << endl;
    return 0;
}