#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=1e4+5;
const int mod=1e9+7;
map<string,pair<int,int>>mp;
int main()
{
    ll n,q;
    cin>>n>>q;
    while(q--)
    {
        ll l,r;
        cin>>l>>r;
        ll tmp=(l+r);
        ll ans=(n/tmp)*2;
        if(n%tmp>=l)
            ans++;
        cout<<ans<<" ";
    }
    return 0;
}
