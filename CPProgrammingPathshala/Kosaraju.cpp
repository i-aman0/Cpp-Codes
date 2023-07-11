#include <bits/stdc++.h>

#define ll long long
#define mod 1e9 + 7

using namespace std;

// Strongly connected components
// if we can go from ant node to any other node in a component, then the component is called scc

// apply dfs and at out time push the node to stack
// reverse the edges of the graph (transpose of the graph)
// again apply dfs on st.top() and mark visited and st.pop()


void v(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand((unsigned int)time(NULL));
}

using namespace std;



int main(){
    v();

    int n;
    cin >> n;

    vector<vector<int> > adj(n);

    for(int i = 0; i < n; i++){
        vector<int> temp;
        cin >> temp[0];
        cin >> temp[1];

        adj.push_back(temp);
    }

    for(auto itr : adj){
        cout << itr[0] << " " << itr[1] << endl;
    }
    
    return 0;
}