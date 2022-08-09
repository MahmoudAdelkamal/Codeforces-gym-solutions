#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int N=1e6+5;
const int mod=1e9+7;
ll n,a[N],dp[N];
ll solve(int idx)
{
    if(idx==n)
        return 1;
    ll &ret = dp[idx];
    if(ret!=-1)
        return ret;
    ret = solve(idx+1)%mod;
    ret = (ret%mod + (solve(idx+1)%mod*a[idx]%mod)%mod)%mod;
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(ll i=0;i<n;i++)
            cin>>a[i];
        memset(dp,-1,sizeof(dp));
        cout<<solve(0)-1<<endl;
    }
    return 0;
}