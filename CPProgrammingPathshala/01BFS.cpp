#include<iostream>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>

#define ll long long

using namespace std;

vector<int> bfs01(vector<vector<pair<int,int> > > graph, int src)
{
    // for(auto itr:graph)
    // {
    //     for(auto it:itr)
    //     {
    //         cout<<it.first<<" "<<it.second<<"   ";
    //     }
    //     cout<<"\n";
    // }
    int n=graph.size();
    vector<int> ans(n,-1);

    int dis=0;
    queue<int> current_dist;
    current_dist.push(src);
    while(current_dist.size())
    {
        queue<int> next_dist;
        while(current_dist.size())
        {
            int node= current_dist.front();
            current_dist.pop();
            if(ans[node]!=-1)
            {
                continue;
            }
            ans[node]=dis;
            for(auto itr:graph[node])
            {
                if(ans[itr.first]==-1)
                {
                    if(itr.second==0)
                    {
                        current_dist.push(itr.first);
                    }
                    else{
                        next_dist.push(itr.first);
                    }
                }
            }
        }
        current_dist=next_dist;
        dis++;
    }
    return ans;
}


int main()
{
    int n;
    int m;
    cin>>n>>m;
    vector<vector<pair<int,int> > > graph(n);
    for(int i=0;i<m;i++)
    {
        int x,y,price;
        cin>>x>>y>>price;
        graph[x].push_back(make_pair(y,price));
        graph[y].push_back(make_pair(x,price));
    }
    vector<int> ans = bfs01(graph,0);
    for(auto itr:ans)
    {
        cout<<itr<<" ";
    }
    cout<<"\n";

}