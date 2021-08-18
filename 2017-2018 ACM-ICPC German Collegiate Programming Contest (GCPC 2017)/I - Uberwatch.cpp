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
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll N = 300001, NN = 1e4 * 8 + 2, mod = 1e9 + 7;
int n, m;
vector<int> v(N);
int dp[N];

int solve(int indx) {
    if (indx >= n)return 0;
    int &ret = dp[indx];
    if (~ret)return ret;
    ret = 0;
    ret = max(ret, solve(indx + m) + v[indx]);
    ret = max(ret, solve(indx + 1));
    return ret;
}

void a() {
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    cout << solve(m);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        a();
    }
    return 0;
}