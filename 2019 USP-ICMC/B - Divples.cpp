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

const ll N = 2501, NN = 1e4 * 8 + 2, mod = 998244353;

void b() {
    ll a, b;
    cin >> a >> b;
    vector<ll> v;
    for (ll i = 1; i * i <= a; ++i) {
        if (a % i == 0) {
            if (i % b == 0) {
                v.eb(i);
            }
            if ((a / i) % b == 0 and i != (a / i)) {
                v.eb(a / i);
            }
        }
    }
    sort(v.begin(), v.end());
    for (auto i : v)cout << i << " ";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        b();
    }
    return 0;
}