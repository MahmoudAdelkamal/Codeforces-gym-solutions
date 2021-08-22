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

const ll N = 1e5 + 5, NN = 1e4 * 8 + 2, mod = 998244353;
map<ll, ll> p;
vector<int> ok;

bool check(ll n) {
    if (n == 1)return false;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0)return false;
    }
    return true;
}

vector<int> a;

ll get(ll m) {
    ll Ans = 0;
    for (auto &i : a)Ans += abs(m - i);
    return Ans;
}

void j() {

    int n;
    cin >> n;
    a.resize(n);
    for (auto &i : a)cin >> i;
    sort(a.begin(), a.end());
    ll med = 0, tmp = 0;
    if (n % 2)med = a[n / 2];
    else med = (a[n / 2] + a[(n / 2) - 1]) / 2;
    tmp = med;
    while (check(tmp) == 0)tmp--;
    while (check(med) == 0)med++;
    if (check(tmp) == 0)tmp = 1e18;
    if (check(med) == 0)med = 1e18;
    cout << min(get(tmp), get(med)) << "\n";


}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        j();
    }
    return 0;
}