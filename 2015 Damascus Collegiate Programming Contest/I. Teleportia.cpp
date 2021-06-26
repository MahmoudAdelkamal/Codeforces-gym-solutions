#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#define ll long long
using namespace std;
const int N = 1e2+5;
const int mod = 1e9+7;
ll n,adj[N][N],x[N],y[N],r[N],dist[N];
ll dis(ll i,ll j)
{
    return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
bool valid(ll i,ll j)
{
    return ((x[i]-x[j])*(x[i] - x[j]))+((y[i]-y[j])*(y[i]-y[j]))<=r[i]*r[i];
}
ll dijkestra()
{
    set<pair<ll,ll>>st;
    st.insert({0,0});
    for(int i=0;i<=n;i++)
        dist[i] = 1e18;
    while(!st.empty())
    {
        auto it = st.begin();
        ll node = it->first, cost = it->second;
        st.erase(it);
        if(cost>dist[node])
            continue;
        for(int i=0;i<n;i++)
        {
            ll new_cost = cost + adj[node][i];
            if (new_cost<dist[i])
            {
                st.insert({i,new_cost});
                dist[i] = new_cost;
            }
        }
    }
    return dist[1];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        n+=2;
        for(int i=2;i<n;i++)
            cin>>x[i]>>y[i]>>r[i];
        cin>>x[0]>>y[0]>>x[1]>>y[1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                adj[i][j] = dis(i,j);
                if (i>=2 && j>=2 && valid(i,j))
                    adj[i][j] = min(adj[i][j],(ll)2);
            }
        }
        cout<<dijkestra()<<"\n";
    }
    return 0;
}