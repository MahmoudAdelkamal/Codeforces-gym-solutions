#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=1e4+5;
const int mod=1e9+7;
ll dp[N][1000][3];
ll n,m,p[N],w[N],d[N];
ll solve(ll idx,ll weight,ll cur)
{
    if(cur<0)
        return INT_MIN;
    if(weight<-200)
        return INT_MIN;
    if(idx==n)
    {
        if(weight>=0)
            return 0;
        return INT_MIN;
    }
    if(dp[idx][weight+200][cur]!=-1)
        return dp[idx][weight+200][cur];
    ll choice1=solve(idx+1,weight,cur);
    ll choice2 = max(solve(idx+1,weight-w[idx],cur),solve(idx+1,weight-w[idx]+d[idx],cur-1))+p[idx];
    return dp[idx][weight+200][cur]=max(choice1,choice2);
}
int main()
{
    cin>>n>>m;
    for(ll i=0;i<n;i++)
    {
        cin>>p[i]>>w[i]>>d[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<solve(0,m,2);
    return 0;
}
