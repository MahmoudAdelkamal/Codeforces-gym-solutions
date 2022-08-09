#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int N=2e5+5;
const int mod=1e9+7;
int n,a[N],pos[N];
int dp[N];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        memset(pos,-1,sizeof(pos));
        dp[1] = 0,pos[a[1]] = 1;
        for(int i=2;i<=n;i++)
        {
            dp[i] = dp[i-1]+1;
            if(pos[a[i]]!=-1)
                dp[i] = min(dp[i],dp[pos[a[i]]]+1);
            pos[a[i]] = i;
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}