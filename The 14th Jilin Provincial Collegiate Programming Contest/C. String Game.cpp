#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <iomanip>
#include <map>
#include <queue>
#include <utility>
#include <stack>
#include <unordered_map>
#define ll long long
using namespace std;
const int N = 1e6+5;
const int mod = 1e9+7;
string s1,s2;
int dp[5005][1005];
int solve(int i, int j)
{
    if(j==s2.size())
        return 1;
    if(i==s1.size())
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    dp[i][j] = 0;
    if(s1[i]==s2[j])
        dp[i][j] = (dp[i][j] + solve(i+1,j+1))%mod;
    dp[i][j] = (dp[i][j] + solve(i+1,j))%mod;
    return dp[i][j];
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin>>s1>>s2)
    {
 
        for(int i=0;i<5005;i++)
        {
            for(int j=0;j<1005;j++)
                dp[i][j] = -1;
        }
        cout<<solve(0,0)<<endl;
    }
    return 0;
}