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

const ll N = 2e4 + 5, NN = 1e4 * 8 + 2, mod = 998244353;
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
void c()
{
    pair<int,int>p[N];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p[i].first>>p[i].second;
    }
    sort(p,p+n);
    int ans = 0;
    for(int i=0;i<n-1;i++)
    {
        if(p[i].first!=p[i+1].first)
            continue;
        for(int j=i+2;j<n-1;j++)
        {
            if(p[i].first==p[j].first || p[j].second<p[i].second || p[j].second > p[i+1].second)
                continue;
            // 1 1
            // 1 2
            // 2 1
            // 2 2
            // is rectangle
            bool valid = (p[j].second==p[i].second && p[i+1].second==p[j+1].second && p[j].first==p[j+1].first);
            if(valid)
                ans++;
            else
                break;
        }
    }
    cout<<ans<<endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    //calcFacAndInv();
    for (int i = 1; i <= t; ++i) {
        c();
        //hbal();
    }
    return 0;
}