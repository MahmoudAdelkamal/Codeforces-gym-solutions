#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const int N = 2e6+10;
const int mod = 998244353;
const double eps = 1e-9;
int n;
ll dp[N][7];
ll add_mod(ll x,ll y)
{

    return (x%mod + y%mod)%mod;
}
ll solve(int len,int prv)
{


 //cout << len << " "<< prv << endl;
    if(len>n)
        return 0;
    if(len==n)
    {

        return (prv==1 || prv==5);
    }
     if(~dp[len][prv])
            return dp[len][prv];
        ll ans=0;
    if(prv==1)
    {
        ans=add_mod(ans,solve(len+1,4));
        ans=add_mod(ans,solve(len+2,5));

    }
    if(prv==2)
    {
        ans=add_mod(ans,solve(len+2,3));
        ans=add_mod(ans,solve(len+2,6));

    }
    if(prv==3)
    {
        ans=add_mod(ans,solve(len+2,1));
        ans=add_mod(ans,solve(len+1,2));
    }
    if(prv==4)
    {
        ans=add_mod(ans,solve(len+2,1));
        ans=add_mod(ans,solve(len+1,2));
    }
    if(prv==5)
    {
        ans=add_mod(ans,solve(len+1,4));
        ans=add_mod(ans,solve(len+2,5));
    }
    if(prv==6)
    {
        ans=add_mod(ans,solve(len+2,3));
        ans=add_mod(ans,solve(len+2,6));
    }
    return dp[len][prv]=ans;
}
int main()
{

int t=1;
while(t--)
{
    memset(dp,-1,sizeof(dp));
   cin>>n;
   cout<<add_mod(solve(2,1),solve(1,2))<<endl;
}

    return 0;
}
