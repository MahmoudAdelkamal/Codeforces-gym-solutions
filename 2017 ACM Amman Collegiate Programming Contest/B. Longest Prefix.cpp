#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int N=1e5+5;
int main()
{
    string a,b;
    ll t,n;
    cin>>t;
    while(t--)
    {
         ll ans=0;
         map<char,ll>mp;
         cin>>a>>b;
         for(ll i=0;i<b.size();i++)
            mp[b[i]]++;
         for(ll i=0;i<a.size();i++)
         {
             if(!mp[a[i]])
                 break;
             ans++;
             mp[a[i]]--;
         }
         cout<<ans<<endl;
    }
   return 0;
}
