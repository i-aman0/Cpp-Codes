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

    cout << endl;
    return 0;
}