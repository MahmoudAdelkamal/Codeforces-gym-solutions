#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <iomanip>
#include <set>
using namespace std;
#define ll long long
const int mod = 1000000007;
const int N = 2e5+5;
int n,dp[N][3];
string s;
int solve(int idx,int prv)
{
    if (idx==n)
        return 0;
    int &ret = dp[idx][prv];
    if (ret!=-1)
        return ret;
    if (s[idx]=='3' && prv==1)
        return ret = solve(idx+1,prv)+1;
    return ret = min(solve(idx+1,prv)+1,solve(idx+1,(s[idx]=='1')));
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    memset(dp,-1,sizeof dp);
    cin>>s;
    n = s.size();
    cout<<solve(0,2)<<'\n';
    return 0;
}