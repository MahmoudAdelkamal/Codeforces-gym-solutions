#include<bits/stdc++.h>
#define ll long long
#define TEKA ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
 
ll dp[100][11];
int arr[100],n;
string s;
 
 
ll solve(int len,int last,bool flag)
{
    if (len==0)     return 1;
    if (dp[len][last]!=-1&&!flag) return dp[len][last];
 
    int tmp=(!flag)?9:arr[len];
    ll ans=0;
    for (int i=last; i<=tmp; i++)
    {
        ans+=solve(len-1,i,flag&&i==arr[len]);
    }
    if (!flag) dp[len][last]=ans;
    return ans;
}
int main()
{
    int t;
    cin>>t;
    memset(dp,-1,sizeof(dp));
    while (t--)
    {
        cin>>s;
        int not_ramp=0,i,j;
        n=s.size();
        for (i=0; i<n; i++)
        {
            arr[n-i]=s[i]-'0';
            if (i!=0&&s[i]<s[i-1]) not_ramp=1;
        }
        ll ans=0;
        for (j=1; j<=arr[n]; j++)
        {
            ans+=solve(n-1,j,j==arr[n]);
        }
 
        for (i=n-1; i>0; i--)
        {
            for (j=1; j<=9; j++)
            {
                ans+=solve(i-1,j,0);
            }
        }
        if (not_ramp)cout<<"-1\n";
        else cout<<ans<<"\n";
    }
    return 0;
}