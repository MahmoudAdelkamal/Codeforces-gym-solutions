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
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void err() { cerr << endl; }

template<typename Head, typename ...Tail>
void err(Head H, Tail ... T) { cerr << " " << to_string(H), err(T...); }

const ll N = 1e6 + 100, NN = 1e4 * 8 + 2, mod = 998244353;
ll fact[N + 1], inv[N + 1];


// nCr and nPr with MOD
//--------------------


ll ncr(ll n, ll r) {
    if (n < r)
        return 0;
    return ((fact[n] * inv[r]) % mod * inv[n - r]) % mod;
}

ll fp(ll base, ll exp) {
    if (exp == 0)
        return 1;
    ll ans = fp(base, exp / 2);
    ans = (ans * ans) % mod;
    if (exp % 2 != 0)
        ans = (ans * (base % mod)) % mod;
    return ans;
}

void calcFacAndInv() {
    fact[0] = inv[0] = 1;
    for (ll i = 1; i <= N; i++) {
        fact[i] = (i * fact[i - 1]) % mod;
        inv[i] = fp(fact[i], mod - 2);
    }
}


vector<int> a;
int n;
bool ff = 0;

ll count(vector<int> a) {
    ll Ans = 0;
    ff = 0;
    for (int i = 1; i + 1 < a.size(); i++) {
        if (a[i] * a[i] < a[i - 1] * a[i + 1]) {
            ff = 1;
        }
        Ans += (a[i] * a[i] >= (a[i - 1] * a[i + 1]));
    }
    return Ans;
}

ll C = 0, ok = 0, Co;

void solve(ll j) {
    if (j == n) {
        for (auto x : a)cout << x << " ";
        cout << endl;
        //cout << count(a) << "\n";
        Co += ff;
        ok++;
        C += count(a);
        return;
    }
    for (int i = 0; i <= 2; i++) {
        a.push_back(i);
        solve(j + 1);
        a.pop_back();
    }
}

void hbal() {
    cin >> n;
    solve(0);
    cout << fp(3, n) << endl;
    int cntt = 0;
    cout << fact[n] << endl;
    cout << "dif " << ok - Co << endl;
    cout << Co << "\n";

}

vector<int> vMax1, vMAx2, vMin1, vMin2;
vector<int> v;
ll dp[N][5];
vector<vector<int>> vv;

ll solway(ll i, ll prv) {

    if (i + 1 == vv.size())return 0;
    ll &ret = dp[i][prv];
    if (~ret)return ret;
    ll Ans = 0;
    for (int k = 0; k < vv[i].size(); k++) {
        if (k == prv && vv[i].size() != 1)continue;
        for (int j = 0; j < vv[i + 1].size(); j++) {
            Ans = max(Ans, solway(i + 1, j) + abs(vv[i][k] - vv[i + 1][j]));
        }
    }
    return ret = Ans;
}

void e() {

    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    map<ll, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        mp[u].push_back(v);
    }
    for (auto it : mp) {
        sort(it.second.begin(), it.second.end());
        if (it.second.size() <= 4)
            vv.push_back(it.second);
        else
            vv.push_back(
                    {it.second[0], it.second[1], it.second[it.second.size() - 1], it.second[it.second.size() - 2]});
    }
    ll ans = 0;
    for (int i = 0; i < vv[0].size(); i++) {
        ans = max(ans, solway(0, i));
    }
    cout << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    //calcFacAndInv();
    for (int i = 1; i <= t; ++i) {
        e();
    }
    return 0;
}