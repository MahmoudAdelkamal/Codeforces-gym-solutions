#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=2e5+5;
const ll mod=1000000007;
int dp[105][10005],n,a[105];
int solve(int idx,int diff)
{
    if(idx==n)
        return abs(diff);
    if(dp[idx][diff+10000]!=-1)
        return dp[idx][diff+10000];
    dp[idx][diff+10000]=max(abs(diff),solve(idx+1,diff+a[idx]));
    dp[idx][diff+10000]=min(dp[idx][diff+10000],max(abs(diff),solve(idx+1,diff-a[idx])));
    return dp[idx][diff+10000];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        memset(dp,-1,sizeof(dp));
        cout<<solve(0,0)<<endl;
    }
   return 0;
}
