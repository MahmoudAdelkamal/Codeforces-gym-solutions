#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;

#define ld long double
#define ll long long
#define ull unsigned long long
#define pb push_back
#define f first
#define s second
#define eb emplace_back
#define endl '\n'
#define eps 1e-9
#define zero(x) (abs (x) < eps)
#define equal(a, b) (zero ((a) - (b)))
#define pi pair<ll,ll>
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll N = 300001, NN = 1e4 * 8 + 2, mod = 1e9 + 7;

ll fp(ll base, ll exp) {
    if (exp == 0)
        return 1;
    ll ans = fp(base, exp / 2);
    ans = (ans * ans) % mod;
    if (exp % 2 != 0)
        ans = (ans * (base % mod)) % mod;
    return ans;
}

ll fact[N + 1], inv[N + 1];

void calcFacAndInv() {
    fact[0] = inv[0] = 1;
    for (ll i = 1; i <= N; i++) {
        fact[i] = (i * fact[i - 1]) % mod;
        inv[i] = fp(fact[i], mod - 2);
    }
}

ll ncr(ll n, ll r) {
    if (n < r)
        return 0;
    return ((fact[n] * inv[r]) % mod * inv[n - r]) % mod;
}

ll npr(ll n, ll r) {
    if (n < r)
        return 0;
    return (fact[n] * inv[n - r]) % mod;
}

void d() {
    calcFacAndInv();
    for (int i = 0; i < 200; ++i) {
        for (int j = 0; j < 200; ++j) {
            if (ncr(i, j) == 838848) {
                cout << "y";
            }
        }
    }
    // cout << npr(16, 4);
}

void b() {
    int n, m, c;
    cin >> n >> m >> c;
    ll v = n * n * m;


}
vector<vector<ll>>adj(N);
pair<ll,ll>a[N];
ll x,n,m,t,dp[1005][1005];
ll solve(ll rem,ll node)
{
    if(rem<0)
        return 2e9;
    if(rem==0 && node==1)
        return 0;
    ll &ret = dp[rem][node];
    if(ret!=-1)
        return ret;
    ret = solve(rem-a[node].first,node)+a[node].second;
    for(auto i:adj[node])
        ret = min(ret, solve(rem-(t+a[i].first),i)+a[i].second);
    return ret;
}
void c()
{
    cin>>x>>n>>m>>t;
    for (ll i = 0; i < m; ++i) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (ll i = 1; i <= n; ++i) {
        cin>>a[i].first>>a[i].second;
    }
    memset(dp,-1,sizeof dp);
    ll ans = solve(x-a[1].first,1)+a[1].second;
    if(ans>=2e9)
        cout<<"It is a trap."<<endl;
    else
        cout<<ans<<endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        c();
    }
    return 0;
}