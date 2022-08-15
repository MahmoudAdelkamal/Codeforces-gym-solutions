#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define pq priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> 
#define graph1 vector<vector<pair<ll,ll>>>
#define graph vector<vector<ll>>
#define pq1 priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll,ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define loop(i,a,b) for (ll i = a; i < b; i++)
using namespace std;
const int N = 1e3+5;
const int mod = 1e9+7;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	ll t;
	cin>>t;
	while(t--)
	{
		int n,ans1 = 1,ans2 = 0;
		cin>>n;
		int arr[n+1],cnt[n+1],dp[n+1];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
			dp[i] = 1;
			cnt[i] = 1;
		}
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(arr[i]>arr[j])
				{
					if(dp[j]+1>dp[i])
					{
						dp[i]  = dp[j]+1;
						cnt[i] = cnt[j];
					}
					else if(dp[j]+1==dp[i])
						(cnt[i]+=cnt[j])%=mod;
				}
			}
			ans1 = max(ans1,dp[i]);
		}
		for(int i=0;i<n;i++)
		{
			if(dp[i]==ans1)
				(ans2+=cnt[i])%=mod;
		}
		cout<<ans1<<" "<<ans2<<endl;
	}
}