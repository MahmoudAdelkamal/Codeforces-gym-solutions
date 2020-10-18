#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=2e5+5;
const ll mod=1000000007;
ll fact[1000006], inv[1000006];
ll fp(ll base, ll exp)
{
    if (exp == 0)
        return 1;
    ll ans = fp(base, exp / 2);
    ans = (ans * ans) % mod;
    if (exp % 2 != 0)
        ans = (ans * (base % mod)) % mod;
    return ans;
}
void calcFacAndInv(ll n)
{
    fact[0] = inv[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
        inv[i] = fp(fact[i], mod - 2);
    }
}
ll ncr(ll n, ll r)
{
    return ((fact[n] * inv[r]) % mod * inv[n - r]) % mod;
}

ll npr(ll n, ll r)
{
    return (fact[n] * inv[n - r]) % mod;
}
ll modInv(ll x,ll mod)
{
    return fp(x,mod-2);
}
ll digits(ll n)
{
    ll cnt=0;
    while(n!=0)
    {
        cnt++;
        n/=10;
    }
    return cnt;
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
        ll n,m,k;
        cin>>m>>n;
        ll num=digits(n);
        ll base=fp(10,num);
        base%=mod;
        ll ans=0;
        ans=n*(fp(base,m)-1);
        ans%=mod;
        ans*=fp(base-1,mod-2)%mod;
        cout<<ans%mod<<endl;
   }
   return 0;
}
