#include <bits/stdc++.h>
#define de7k_gamed ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
typedef long double ld;
using namespace std;
const ll N=1e5+5;
ll h[N];
int main()
{
    de7k_gamed
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,mn=1e9;
        cin>>n;
        for(ll i=0;i<n;i++)
            cin>>h[i],mn=min(mn,h[i]);
        bool ans=true;
        for(ll i=0;i<n;i++)
        {
            if((h[i]-mn)%2!=0)
                ans=false;
        }
        if(ans)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
 	return 0;
}
