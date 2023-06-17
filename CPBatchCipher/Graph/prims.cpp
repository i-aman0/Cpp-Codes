#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

void display(vector<vector<int> > &graph){
    for(auto row : graph){
        for(auto element : row){
            cout << element << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int primsMST(int src, unordered_map<int, list<pair<int, int> > > &adj){
    int minWeight = 0;

    // we are using the greater function and since greater function compares the first element of the collection for comparison 
    // therefore, we are putting weight as the first data in pair
    // because we want to sort the data according to the weight 
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > pq;

    unordered_map<int, bool> mstSet;

    pq.push({0, src}); // 0 is weight and src is the node

    while(!pq.empty()){
        auto node = pq.top();
        pq.pop();

        if(mstSet[node.second]){
            continue;
        }

        mstSet[node.second] = true;
        minWeight += node.first;

        for(auto neighbour : adj[node.second]){
            pq.push({neighbour.second, neighbour.first});
        }
    }

    return minWeight;
}

int main()
{
    vector<vector<int> > graph = {
        {0, 1, 4},  // node 1, node 2, weight between the nodes
        {0, 7, 8},  // i.e. graph[0] and graph[1] nodes and graph[2] weight
        {1, 2, 8},
        {1, 7, 11},
        {2, 3, 7},
        {2, 5, 4},
        {2, 8, 2},
        {3, 4, 9},
        {3, 5, 14},
        {4, 5, 10},
        {5, 6, 2},
        {6, 7, 1},
        {6, 8, 6},
        {7, 8, 7}
    };
    display(graph);

    unordered_map<int, list<pair<int, int> > > adj;

    for(auto edge : graph){
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }

    cout << primsMST(7, adj);
    return 0;
}