#include<bits/stdc++.h>

using namespace std;
#define fastVictory ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define ll long long
#define endl '\n'
const int N = 1e5 + 5;

int par[N];

int Find(int u) {
    if (u == par[u])
        return u;
    return par[u] = Find(par[u]);
}

int main() {
    fastVictory
    ll t;
    cin >> t;
    while (t--) {
        ll n, x;
        cin >> n >> x;
        ll arr[n + 5] = {};
        for (ll i = 1; i <= n; i++) {
            cin >> arr[i];
            arr[i] += arr[i - 1];
        }
        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            ll tmp = lower_bound(arr + 1, arr + n + 1, arr[i] + x) - arr;
            ans += tmp - i - 1;
        }
        cout << ans << endl;
    }
    return 0;
}