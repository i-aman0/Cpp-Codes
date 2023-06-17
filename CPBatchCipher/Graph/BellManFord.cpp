#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

#define UM unordered_map
#define INF 9999

bool relax(vector<vector<int>> &graph, vector<int> &dist){
    bool isRelax = false;

    for(auto edge : graph){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if(dist[v] > dist[u] + w){
            dist[v] = dist[u] + w;
            isRelax = true;
        }
    }

    return isRelax;
}

bool bellmanFord(int src, vector<vector<int>> &graph, vector<int> &dist){
    dist[src] = 0;

    for(int i = 0; i < dist.size() - 1; i++){
        relax(graph, dist);
    }

    return !relax(graph, dist);
}

int main()
{
    vector<vector<int>> graph = {
        {0,1,4},
        {0,7,8},
        {1,2,8},
        {1,7,11},
        {2,3,7},
        {2,5,4},
        {2,8,2},
        {3,4,9},
        {3,5,14},
        {4,5,10},
        {5,6,2},
        {6,7,1},
        {6,8,6},
        {7,8,7}
    };

    vector<int> dist(9, INF);
    int src = 0;
    return 0;
}