
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
const int N=55;
map<ll,ll>mp;
vector<ll>v;
ll n,k,dp[1005][1005],a[1005];
ll solve(int idx,int rem)
{
    if(rem==0)
        return 1;
    if(idx==v.size())
        return 0;
    if(dp[idx][rem]!=-1)
        return dp[idx][rem];
    ll ans=0;
    ans=(ans+solve(idx+1,rem))%mod;
    ans=(ans+solve(idx+1,rem-1)*mp[v[idx]])%mod;
    return dp[idx][rem]=ans;
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
         cin>>a[i];
         mp[a[i]]++;
    }
    for(auto i:mp)
        v.push_back(i.first);
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,k)<<endl;
}
