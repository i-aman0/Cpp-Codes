#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
#include<stack>
using namespace std;

void bfsIterative(int curr, unordered_map<int, list<int> > &adj){
    unordered_map<int, bool> visited;
    queue<int> nodes;

    nodes.push(curr);
    visited[curr] = true;

    while(!nodes.empty()){
        int node = nodes.front();
        nodes.pop();
        cout << node << " ";

        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                nodes.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}

void dfsIterative(int curr, unordered_map<int, list<int> > &adj){
    unordered_map<int, bool> visited;
    stack<int> st;

    st.push(curr);
    visited[curr] = true;

    while(!st.empty()){
        int node = st.top();
        st.pop();
        cout << node << " ";

        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                st.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}

void dfsRecursive(int curr, unordered_map<int, list<int> > &adj, unordered_map<int, bool> &visited){
    cout << curr << " ";
    visited[curr] = true;

    for(int neighbour : adj[curr]){
        if(!visited[neighbour]){
            dfsRecursive(neighbour, adj, visited);
        }
    }
}

void display(unordered_map<int, list<int> > &adjList){
    for(auto kvPair : adjList){
        cout << kvPair.first << ": {";
        for(auto v : kvPair.second){
            cout << v << ",";
        }
        cout << "}" << endl;
    }
}

int main()
{
    vector<pair<int, int> > edges = {
        {1, 3},
        {1, 4},
        {2, 4},
        {2, 8},
        {3, 5},
        {3, 8},
        {4, 8},
        {4, 9},
        {5, 7},
        {6, 7},
        {6, 8}
    };

    unordered_map<int, list<int> > adj;
    for(auto edge : edges){
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
    }

    unordered_map<int, bool> visited;
    display(adj);
    cout << endl;

    cout << "DFS Recursive is : " << endl;
    dfsRecursive(7, adj, visited);

    cout << endl << "DFS Iterative is : " << endl;
    dfsIterative(7, adj);
    
    cout << endl << "BFS Iterative is : " << endl;
    bfsIterative(7, adj);
    return 0;
}