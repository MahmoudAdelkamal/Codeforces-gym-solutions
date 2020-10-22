#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=3e5+5;
const ll mod=1000000007;
int a[200],b[200],n,m;
int dp1[200][15005],dp2[200][15005];
int solve1(int i,int w)
{
    if(i==n)
        return(w==0);
    if(dp1[i][w]!=-1)
        return dp1[i][w];
    dp1[i][w]=solve1(i+1,w);
    if(a[i]<=w)
        dp1[i][w]=(dp1[i][w]+solve1(i+1,w-a[i]))%mod;
    return dp1[i][w];
}
int solve2(int i,int w)
{
    if(i==m)
        return(w==0);
    if(dp2[i][w]!=-1)
        return dp2[i][w];
    dp2[i][w]=solve2(i+1,w);
    if(b[i]<=w)
        dp2[i][w]=(dp2[i][w]+solve2(i+1,w-b[i]))%mod;
    return dp2[i][w];
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        int ans=0;
        int k,w;
        cin>>n>>m;
        cin>>k>>w;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        memset(dp1,-1,sizeof dp1);
        memset(dp2,-1,sizeof dp2);
        for(int i=0;i<=w;i++)
        {
            int dif=w-i;
            if(abs(i-dif)>k)
               continue;
            int ans1=solve1(0,dif);
            int ans2=solve2(0,i);
            ans=(ans+(1LL*ans1*ans2)%mod)%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
