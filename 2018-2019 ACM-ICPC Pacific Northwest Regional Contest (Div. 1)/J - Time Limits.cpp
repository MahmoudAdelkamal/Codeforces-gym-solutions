#include <bits/stdc++.h>
#define de7k_gamed ios_base::sync_with_stdio(false);cin.tie(NULL);//freopen("out.txt","w",stdout);
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
int main()
{
    ll n,s,mx=0;
    cin>>n>>s;
    for (ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        mx=max(mx,x);
    }
    mx*=s;
    cout<<(ll)(mx+999)/1000<<'\n';
    return 0;
}
