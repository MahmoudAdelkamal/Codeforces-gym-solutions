#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+9;
const int N=1e6+7;
int b,k,dp[130][130][1005],pw[130];
int solve(int idx,int ones,int cur)
{
    if(idx==b)
    {
        if(cur==0)
            return ones;
        return 0;
    }
    if(dp[idx][ones][cur]!=-1)
        return dp[idx][ones][cur];
    dp[idx][ones][cur] = solve(idx+1,ones,cur);
    dp[idx][ones][cur] = (dp[idx][ones][cur] + solve(idx+1,ones+1,(cur+pw[idx])%k))%mod;
    return dp[idx][ones][cur];
}
int main()
{
    cin>>k>>b;
    memset(dp,-1,sizeof(dp));
    pw[0]=1;
    for(int i=1;i<b;i++)
    {
        pw[i]=(pw[i-1]+pw[i-1])%k;
    }
    cout<<solve(0,0,0);
    return 0;
}
