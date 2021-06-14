#include <bits/stdc++.h>
#define yala ios::sync_with_stdio(0); cin.tie(0); ios_base::sync_with_stdio(0);
//#define RW freopen(".in","r",stdin)
#define ll long long
#define ld long double
using namespace std;
const int N = 2e5 + 9;
const int MOD = 1e9;
const ll INF = 1e18;
const double pi = 3.1415926536;
const int mod = 1e9 + 7;
typedef complex<ll>point;
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};
ll fact[N], inv[N];
ll modPower(ll b, ll p) {
    if (p == 0)
        return 1;
    ll halfpow = modPower(b, p / 2);
    ll toReturn = (halfpow * halfpow) % mod;
    if (p % 2)
        toReturn = (toReturn * b) % mod;
    return toReturn;
}
void pre(ll n) {
    fact[0] = 1;
    inv[0] = 1;
    for (ll i = 1; i <= n; i++) {
        fact[i] = (i * fact[i - 1]) % mod;
        inv[i] = modPower(fact[i], mod - 2);
    }
}
ll ncr(ll n, ll r) {
    return ((((fact[n] * inv[n - r]) % mod) * inv[r]) % mod);
}
int main() {
    yala;
    pre(N);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll ans = ncr((1ll * 2 * n) - 1, n) % mod;
        cout << ans << '\n';
    }
    return 0;
}