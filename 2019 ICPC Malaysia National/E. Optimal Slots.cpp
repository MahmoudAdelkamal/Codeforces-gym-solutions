#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+5;
vector<int>ans;
int t,n,a[N],dp[N][N];
int solve(int idx,int sum)
{
    if(idx==n)
        return 0;
    int &ret = dp[idx][sum];
    if(ret!=-1)
        return ret;
    ret = solve(idx+1,sum);
    if(sum+a[idx]<=t)
        ret = max(ret,solve(idx+1,sum+a[idx])+a[idx]);
    return ret;
}
void build(int idx,int sum)
{
    if(idx==n)
        return;
    if(dp[idx][sum]==solve(idx+1,sum+a[idx])+a[idx])
    {
        ans.push_back(a[idx]);
        build(idx+1,sum+a[idx]);
    }
    else
        build(idx+1,sum);
}
int main()
{
    while(cin>>t)
    {
        if(!t)
            break;
        ans.clear();
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        memset(dp,-1,sizeof(dp));
        int res = solve(0,0);
        build(0,0);
        ll sum = 0;
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        cout<<res<<endl;
    }
    return 0;
}