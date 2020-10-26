#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
const int N=55;
int main()
{
    map<ll,ll>mp;
    ll n;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        for(ll j=a;j<=b;j++)
             mp[j]++;
    }
    ll ans=-1;
    for(ll i=0;i<=n;i++)
    {
        if(mp[i]==i)
            ans=i;
    }
    cout<<ans;
}
