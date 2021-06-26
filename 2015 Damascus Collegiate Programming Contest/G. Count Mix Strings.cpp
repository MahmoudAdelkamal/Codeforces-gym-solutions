#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#define ll long long
using namespace std;
const int N = 1e4+5;
const int mod = 1e9+7;
int dp[N][N];
int solve(int i,int j)
{
    if(i<0 || j<0)
        return 0;
    if(!i && !j)
        return 1;
    if(dp[i][j]!=-1)
        return dp[i][j];
    return dp[i][j] = (solve(i-1,j)%mod + solve(i,j-1)%mod)%mod;
}
int main()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            dp[i][j] = -1;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
            solve(i,j);
    }
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        cout<<dp[n][m]<<"\n";
    }
    return 0;
}