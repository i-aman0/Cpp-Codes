#include<iostream>
using namespace std;

class DisjointSet{
    vector<int> rank;
    vector<int> parent;
public:
    DisjointSet(int n){
        rank.resize(n + 1, 0); // the rank array is initially 0
        parent.resize(n + 1);

        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }

    int findUltimateParent(int node){
        if(node == parent[node]){
            return node;
        }

        // return findUltimateParent(parent[node]); TC = O(log N)
        return parent[node] = findUltimateParent(parent[node]); // optimised approach path compression
    }

    void unionByRank(int u, int v){
        int parentU = findUltimateParent(u);
        int parentV = findUltimateParent(v);

        if(parentU == parentV){ // they belong to the same component, so no need to do the union again
            return;
        }

        if(rank[parentU] < rank[parentV]){
            parent[parentU] = parentV;
        }
        else if(rank[parentV] < rank[parentU]){
            parent[parentV] = parentU;
        }
        else{ // if both have similar rank, attach v to u and increase the rank of u
            parent[parentV] = parentU;
            rank[parentU]++;
        }
    }
    
};

int main()
{
    DisjointSet ds(7);

    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // check whether 3 and 7 belong to the same component or not 
    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
        cout << "Same component" << endl;
    }
    else{
        cout << "Different components" << endl;
    }

    ds.unionByRank(3, 7);

    if(ds.findUltimateParent(3) == ds.findUltimateParent(7)){
        cout << "Same component" << endl;
    }
    else{
        cout << "Different components" << endl;
    }
    
    return 0;
}