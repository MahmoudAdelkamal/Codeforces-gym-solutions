#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <iomanip>
#include <map>
#include <queue>
#include <utility>
#include <stack>
#include <unordered_map>
#define ll long long
using namespace std;
const int N = 1e6+5;
const int mod = 1e9+7;
vector<vector<int>>adj(N);
ll ind[N];
ll manager[N];
ll ans[N];
void dfs(int node)
{
    for(int i=0;i<adj[node].size();i++)
    {
        int child = adj[node][i];
        dfs(child);
        manager[node]+=manager[child];
        ans[node]+=ans[child];
    }
    ind[node]+=manager[node];
    ans[node]+=ind[node];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        adj[x].push_back(i);
    }
    for(int i=0;i<m;i++)
    {
        int M,node,v;
        cin>>M>>node>>v;
        if(M==1)
            ind[node]+=v;
        else
            manager[node]+=v;
    }
    dfs(0);
    while(q--)
    {
        int t,e;
        cin>>t>>e;
        t==1?cout<<ind[e]<<"\n":cout<<ans[e]<<"\n";
    }
    return 0;
}