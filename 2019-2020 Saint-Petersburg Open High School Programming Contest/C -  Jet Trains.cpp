#include<iostream>
#include <queue>
#include <set>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <cmath>
using namespace std;
#define ll long long
const int N = 3e5+5;
int par[N], sz[N], cnt[N];
unordered_set<int>adj[N];
unordered_set<int>c[N];
int Find(int u)
{
    if (u == par[u])
        return u;
    return par[u] = Find(par[u]);
}
void connect(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if(u==v)
        return;
    if (sz[u] > sz[v])
        swap(u,v);
    par[u] = v;
    sz[v]+=sz[u];
    for(auto i:c[u])
    {
        for(auto j:adj[i])
        {
             if(c[v].count(j))
             {
                 cnt[i]++;
                 cnt[j]++;
             }
        }
    }
    for(auto i:c[u])
        c[v].insert(i);
    c[u].clear();
}
bool is_conn(int u, int v)
{
    return (Find(u) == Find(v));
}
void init()
{
    for (int i = 0; i < N; i++)
        par[i] = i, sz[i] = 1, cnt[i] = 0,c[i].insert(i);
}
int main()
{
    init();
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for(int i=0;i<k;i++)
    {
        int u,v;
        cin>>u>>v;
        connect(u,v);
    }
    int q;
    cin>>q;
    while(q--)
    {
        char op;
        cin>>op;
        if(op=='?')
        {
            int u;
            cin>>u;
            cout<<cnt[u]<<endl;
        }
        else if(op=='F')
        {
            int u,v;
            cin>>u>>v;
            adj[u].insert(v);
            adj[v].insert(u);
            if(is_conn(u,v))
                cnt[u]++,cnt[v]++;
        }
        else if(op=='T')
        {
            int u,v;
            cin>>u>>v;
            connect(u,v);
        }
    }
    return 0;
}