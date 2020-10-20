#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=1e3+5;
const ll mod=1000000007;
int n,a,b;
int dp[50005][2];
int solve(int rem,bool prv)
{
    if(rem<0)
        return 0;
    if(rem==0)
        return 1;
    if(dp[rem][prv]!=-1)
        return dp[rem][prv];
    dp[rem][prv]=0;
    if(prv==0)
    {
        for(int i=1;i<=a;i++)
            dp[rem][prv]=(dp[rem][prv]%mod)+solve(rem-i,!prv)%mod;
        dp[rem][prv]%=mod;
    }
    else
    {
        for(int i=1;i<=b;i++)
            dp[rem][prv]=(dp[rem][prv]%mod)+solve(rem-i,!prv)%mod;
        dp[rem][prv]%=mod;
    }
    return dp[rem][prv]%mod;
}
int main()
{
    cin>>n>>a>>b;
    memset(dp,-1,sizeof(dp));
    cout<<((solve(n,0)%mod)+(solve(n,1)%mod))%mod;
    return 0;
}
