#include <bits/stdc++.h>
 
#define sr3 ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
const int N = 2e5 + 5, inf = 2e9, mod = 1e9 + 7;
 
 
int main() {
    sr3
    ll n,ans=0; cin>>n;
    ll arr[60]={};
    ll dp[60][2]={};
    for(int i=0; i<n; i++)
        cin>>arr[i];
    for(int i=0; i<n; i++){
        dp[i][0]=dp[i][1]=0;
        for(int j=0; j<i; j++){
            if(arr[j]>arr[i])dp[i][0]=max(dp[i][0],dp[j][1]);
            else if(arr[i]>arr[j])dp[i][1]=max(dp[i][1],dp[j][0]);
        }
         dp[i][0]++,dp[i][1]++;
         ans=max({ans,dp[i][0],dp[i][1]});
    }
    cout<<ans<<endl;
    return 0;
}