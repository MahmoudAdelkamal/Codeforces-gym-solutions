#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2500;
const int mod = 1e9+7;
int n,e,k;
int dp[N][N];
bool cant[N][N];
int solve(int idx,int mask)
{
      if(idx==n)
      return 1;
      int &ret = dp[idx][mask];
      if(ret!=-1)
         return ret;
      ret = 0;
      for(int i=-e;i<=e;i++)
      {
          int first = idx,second = idx+i;
   	  if(second<0 || second>=n || cant[first][second])
  	     continue;
	  if((mask>>(i+e))&1)
             continue;
  	  ret = (ret%mod+solve(idx+1,(mask|(1<<(i+e)))>>1)%mod)%mod;
      }
      return ret;
}
int main()
{
	memset(dp,-1,sizeof dp);
	cin>>n>>e>>k;
	while(k--)
        {
		int a,b;
		cin>>a>>b;
                a--,b--;
		cant[a][b] = 1;
	}
	cout<<solve(0,0);
	return 0;
}