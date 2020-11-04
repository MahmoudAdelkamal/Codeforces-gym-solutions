#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int N=2e5+5;
ll fact[N], inv[N];
ll fp(ll base, ll exp)
{
    if (exp == 0)
        return 1;
    ll ans = fp(base, exp / 2);
    ans = (ans * ans) % mod;
    if (exp % 2 != 0)
        ans = (ans * (base % mod)) % mod;
    return ans;
}
ll dp[2][N];
void calcFacAndInv(ll n)
{
    fact[0] = inv[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
        inv[i] = fp(fact[i], mod - 2);
    }
}
ll ncr(ll n, ll r)
{
    return ((fact[n] * inv[r]) % mod * inv[n - r]) % mod;
}
ll npr(ll n, ll r)
{
    return (fact[n] * inv[n - r]) % mod;
}
ll calc(ll rows,ll cols)
{
    for (ll i=0;i<cols;i++)
        dp[0][i]=1;
    bool x=1;
    for (ll i=1;i<rows;i++)
    {
        dp[x][0]=1;
        for (ll j=1;j<cols;j++)
            dp[x][j]=((dp[!x][j]%mod)+(dp[x][j-1]%mod))%mod;
        x=!x;
    }
    return dp[!x][cols-1]%mod;
}
ll solve(ll n,ll r)
{
    return ncr(n+r-2,r-1);
}
int main()
{
    calcFacAndInv(N);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,m,x,y;
        cin>>n>>m>>x>>y;
        n--,m--,x--,y--;
        ll ans = ncr(n+m,m)-(ncr(x+y,y)*ncr(n-x+m-y,m-y));
        ans%=mod;
        if(ans<0)
            ans+=mod;
        cout<<ans<<endl;
    }
    return 0;
}
