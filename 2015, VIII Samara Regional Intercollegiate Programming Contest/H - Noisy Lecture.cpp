#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=1e5+5;
const int mod=1e9+7;
int main()
{
    ll n,a[N],b[N];
    cin>>n;
    for(ll i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(ll i=0;i<n;i++)
        cin>>b[i];
    ll k,ans=0;
    cin>>k;
    for(ll i=0;i<k;i++)
    {
        ll x;
        cin>>x;
        ans+=x;
    }
    ans+=k*a[n-1];
    cout<<ans;
    return 0;
}
