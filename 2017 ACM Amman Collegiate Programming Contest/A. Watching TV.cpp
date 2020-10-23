#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int N=1e5+5;
int main()
{
    ll t,n;
    cin>>t;
    while(t--)
    {
        vector<ll>v;
        ll maxi=INT_MIN,ans=INT_MAX,arr[N];
        map<ll,ll>mp;
        cin>>n;
        string s;
        for(ll i=0;i<n;i++)
        {
            cin>>s>>arr[i];
            mp[arr[i]]++;
            maxi=max(maxi,mp[arr[i]]);
        }
        for(ll i=0;i<n;i++)
        {
            if(mp[arr[i]]==maxi)
                ans=min(ans,arr[i]);
        }
        cout<<ans<<endl;
    }
   return 0;
}
