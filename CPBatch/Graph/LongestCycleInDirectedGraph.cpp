#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, int distance, vector<int> &edges, vector<bool> &visited, vector<bool> &extra, vector<int> &distNode, int &ans){
    if(node != -1){
        if(!visited[node]){
            visited[node] = true;
            extra[node] = true;
            distNode[node] = distance;
            dfs(edges[node], distance + 1, edges, visited, extra, distNode, ans);
        }
        else if(extra[node]){
            ans = max(ans, distance - distNode[node]);
        }
        extra[node] = false;
    }
}

int longestCycle(vector<int> &edges){
    int n = edges.size();
    vector<bool> visited(n, false);
    vector<bool> extra(n, false);
    vector<int> distNode(n, 0);

    int ans = -1;

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, 0, edges, visited, extra, distNode, ans);
        }
    }

    return ans;
}

int main()
{
    vector<int> edges = {3,3,4,2,3};
    int res = longestCycle(edges);
    cout << "The length of longest cycle is : " << res << endl;
    return 0;
}