#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
map<ll,ll>mp;
void primefactorization(ll n) {
	if(n%2==0)
        mp[2]++;
    while(n%2==0){
        n/=2;
    }
    for(ll i=3;i*i<=n;i+=2){
        if(n%i==0)
            mp[i]++;
        while(n%i==0)
            n/=i;
    }
    if(n>2)
        mp[n]++;
}
int main()
{
    ll t,n,m,k;
    cin>>t;
    while(t--){
        cin>>n;
        ll arr[n+5],ans=0;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            primefactorization(arr[i]);
        }
        for(auto i:mp){
            ans+=(i.second+2)/3;
        }
        cout<<ans<<endl;
        mp.clear();
    }
  return 0;
}
