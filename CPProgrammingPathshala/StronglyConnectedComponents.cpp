#include <iostream>
#include <vector>
#include <cmath>
#include <ostream>
#include <list>
#include <map>
#include <algorithm>
#include <climits>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <iterator>
#include <deque>
#include <set>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <queue>
#include <chrono>
#include <deque>
#include <string>
#include <unordered_map>
#include<assert.h>
#include <unordered_set>
#define ll long long
using namespace std;
#define mod 998244353
void v()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand((unsigned int)time(NULL));
}


void dfs1(ll node, vector<vector<ll> >& graph,vector<ll>& vis,stack<ll>& st)
{
    vis[node]=1;
    for(auto itr:graph[node])
    {
        if(vis[itr]==0)
        {
            dfs1(itr,graph,vis,st);
        }
    }
    st.push(node);
}

void dfs2(ll node,vector<vector<ll> >& graph,vector<ll>& vis, vector<ll>& component)
{
    vis[node]=1;
    for(auto itr:graph[node])
    {
        if(vis[itr]==0)
        {
            dfs2(itr,graph,vis,component);
        }
    }
    component.push_back(node);
}

int main()
{
    v();
    int t=1;
    // cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<vector<ll> > graph(n+1);
        vector<ll> vis(n+1,0);
        vector<vector<ll> > tgraph(n+1);
        for(ll i=0;i<m;i++)
        {
            ll a,b;
            cin>>a>>b;
            tgraph[b].push_back(a);
            graph[a].push_back(b);
        }
        stack<ll> st;
        for(ll i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                dfs1(i,tgraph,vis,st);
            }
        }

        ll mot=st.top();
        for(ll i=1;i<=n;i++)
        {
            vis[i]=0;
        }
        stack<ll> nst;
        dfs1(mot,tgraph,vis,nst);
        if(nst.size()!=n)
        {
            cout<<0<<"\n";
            return 0;
        }
        for(ll i=1;i<=n;i++)
        {
            vis[i]=0;
        }
        vector<vector<ll> > components;
        while(st.size())
        {
            ll node=st.top();
            st.pop();
            vector<ll> component;
            if(vis[node]==0)
            {
                dfs2(node,graph,vis,component);
            }
            components.push_back(component);
        }
        ll ans=-1;
        for(int i=0;i<components.size();i++)
        {
            for(ll j=0;j<components[i].size();j++)
            {
                if(components[i][j]==mot)
                {
                    ans=i;
                    break;
                }
            }
        }
        cout<<components[ans].size()<<"\n";
        sort(components[ans].begin(),components[ans].end());
        for(auto itr:components[ans])
        {
            cout<<itr<<" ";
        }
        cout<<"\n";
    }
}