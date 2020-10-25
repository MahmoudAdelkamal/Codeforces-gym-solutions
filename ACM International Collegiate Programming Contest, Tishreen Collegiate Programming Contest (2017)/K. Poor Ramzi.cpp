#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int N=55;
string s;
int dp[N][N];
int solve(int st,int en)
{
    if(st>=en)
        return 1;
    if(dp[st][en]!=-1)
        return dp[st][en];
    dp[st][en]=1;
    int tmp1=0;
    for(int i=st;i<en;i++)
    {
        int tmp2 = 0;
        tmp1+=(s[i]=='1');
        for (int j=en;j>i;j--)
        {
            tmp2+=(s[j]=='1');
            if(tmp1==tmp2)
                dp[st][en]=(dp[st][en]+solve(i+1,j-1))%mod;
        }
    }
    return dp[st][en];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>s;
        memset(dp,-1,sizeof(dp));
        cout<<solve(0,s.size()-1)<<endl;
    }
}
