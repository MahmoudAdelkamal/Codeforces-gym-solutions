#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int N=1e5+5;
ll fact[N];
ll factpow[N];
ll sqr(ll a){
	return (a * a) % mod;
}
ll modpow(ll a,ll b){
	if(b == 0) return 1;
	if(b == 1) return a % mod;
	ll tmp = sqr(modpow(a , b >> 1));
	if(b&1) tmp = (tmp * a) % mod;
	return tmp;
}
void init(){
	fact[0] = fact[1] = 1;
	for(int i = 2;i <= N; ++i){
		fact[i] = (fact[i-1] * i) % mod;
	}
	for(int i = 0;i <= N; ++i){
		factpow[i] = modpow(fact[i], mod - 2);
	}
}
ll ncr(int a, int b){
	return (((fact[a] * factpow[b]) % mod) * factpow[a - b]) % mod;
}
int main()
{
    init();
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        cout<<(2*ncr(n-1,m))%mod<<endl;
    }
   return 0;
}
