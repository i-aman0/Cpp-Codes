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

// dijkastra's algo is used to find the shortest path from src to every node 
// the adjacency list will be of the form : 
// {node, {{adjNode1, edgeWeight1}, {adjNode2, edgeWeight2}}}

// Approach:
// create a distance array that will store the minimum distance frm src to a particular node
// a min priority queue DS that will store {weight, node} so that min weight always comes on top
// remove the top node from PQ, compare the distance with preexisting value of that node 
// update the distance if required and push the adjNodes and their weights in PQ, repeat

using namespace std;

vector<int> dijkastra(vector<vector<int>> adj[], int src, int n){

    // create a distance array and set source distance to zero and others to infinity 
    vector<int> distance(n, INT_MAX);
    distance[src] = 0;

    // decalre min priority queue of pair which will store a pair of 
    // {distance, node} --> distance from node for that particular node
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    //push {0, src} into pq 
    pq.push({0, src});

    while(!pq.empty()){

        // pop the top node from PQ 
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // for all the adjacent nodes, check whether the distance of adjNode from current node is less than 
        // the diatance already calculated for adjNode and stored distance vector
        // if that is less, it means that new path to adjNode have been found having lesser distance than previously found paths.
        // In this case, update distance array with new distance and push the adjNode and it's new distance (which will be smaller than the previous one) into the PQ
        for(auto it : adj[node]){
            int adjNode = it[0]; // adjacent node to current node that we popped from pq
            int adjDist = it[1]; // distance if that adj node from current popped node

            if(dist + adjDist < distance[adjNode]){
                distance[adjNode] = dist + adjDist;
                pq.push({distance[adjNode], adjNode});
            }
        }
    }

    return distance;
}

int main(){
    //v();

    
    return 0;
}