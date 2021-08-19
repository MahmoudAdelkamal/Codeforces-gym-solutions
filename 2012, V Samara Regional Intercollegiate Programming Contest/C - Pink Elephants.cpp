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
const int N = 1e3+1;
int n, m;
int dp[205][205];
int solve(int idx, int prv)
{
    if(idx == n)
        return 1;
    int &ans = dp[idx][prv];
    if(ans!=-1)
        return ans;
    ans = 0;
    for(int i = prv + 1; i <= m; i++)
        ans = (ans + solve(idx + 1, i)) % mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0);
    return 0;
}