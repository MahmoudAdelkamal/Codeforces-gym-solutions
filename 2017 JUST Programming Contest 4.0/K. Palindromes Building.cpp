#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int N=2e5+5;
const int mod=1e9+7;
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
int main()
{
    calcFacAndInv(N);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        map<char,int>mp;
        string s;
        int n,ans = 0,cnt = 0;
        cin>>n>>s;
        for(int i=0;i<n;i++)
            mp[s[i]]++;
        for(char i='a';i<='z';i++)
        {
            if(mp[i]%2)
                cnt++;
            mp[i]/=2;
        }
        if(cnt>1)
            cout<<0<<endl;
        else
        {
            ll ans = fact[n/2];
            for(char i='a';i<='z';i++)
                ans/=fact[mp[i]];
            cout<<ans<<endl;
        }
    }
    return 0;
}