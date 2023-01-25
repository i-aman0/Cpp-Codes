#include<iostream>
#include<vector>
#include<unordered_map>
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

int findRoot(int element, unordered_map<int, int> &parent){
    if(element == parent[element]) return element;
    // jo bhi value return ho rhi h(root) use element ka parent set krdo
    // so that no skew tree is formed (called path compression)
    return parent[element] = findRoot(parent[element], parent);
}

bool mergeSet(int element1, int element2, unordered_map<int, int> &parent){
    int root1 = findRoot(element1, parent);
    int root2 = findRoot(element2, parent);

    if(root1 == root2){
        return false; // i.e. we can't merge them (cycle)
    }

    parent[root1] = root2; // merging
    return true;
}

vector<vector<int> > kruskalsMST(vector<vector<int> > &graph, int n){
    // writing a lambda function to sort the elements according to their weights which is present at index 2
    // otherwise it will sort according to the value at index 0
    sort(graph.begin(), graph.end(), [&](auto a, auto b){return a[2] < b[2];});  
    vector<vector<int> > mst;

    unordered_map<int, int> parent;

    // intialise parent for each node
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }

    for(auto edge : graph){
        if(mergeSet(edge[0], edge[1], parent)){
            mst.push_back(edge);
        }
    }

    return mst;
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
    auto mst = kruskalsMST(graph, 9);
    display(mst);
    return 0;
}