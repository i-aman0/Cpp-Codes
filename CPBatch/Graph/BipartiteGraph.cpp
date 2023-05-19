#include<iostream>
#include<queue>
using namespace std;

// given a graph tell whether it is bipartite or not 
// a bipartite is a graph which can be divided into two sets of vertices such that
// no two adjacent vertices have the same color

// I/P : a 2d vector the nodes which are neighbours of the node represented by index i
// https://leetcode.com/problems/is-graph-bipartite/description/

// we use 2 color method to check for bipartite graph
// use BFS (or DFS) to traverse 

// 0 --> uncolored and hence unvisited
// 1 --> blue color
// -1 --> red color

bool isBipartite(vector<vector<int>> &graph){
    int n = graph.size();
    vector<int> color(n, 0); // marking all the nodes as uncolored

    // traversing all the nodes in case the graph has disconnected components
    for(int node = 0; node < n; node++){

        // if the node is alreasy visited no need to visit again
        if(color[node] != 0){
            continue;
        }

        // starting the BFS traversal
        queue<int> q;
        q.push(node);
        color[node] = 1; // coloring the first node as blue

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            // traversing over all the neighbours of the current node
            for(auto neigh : graph[curr]){

                if(color[neigh] == 0){ // unvisited
                    color[neigh] = -color[curr]; // color it in the opposite color of the neighbour(curr) node
                    q.push(neigh);
                }

                // if visited, the color of the neighbour should be opposite the color of current node
                // otherwise return false
                else if(color[neigh] != -color[curr]){
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> graph {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    
    bool ans = isBipartite(graph);

    cout << "Is the graph bipartite : " << ans << endl;
    return 0;
}