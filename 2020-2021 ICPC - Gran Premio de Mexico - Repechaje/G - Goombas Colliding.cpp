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
int main() {
    yala;
    ll l, g;
    cin >> l >> g;
    ll mx = -1;
    for (int i = 0; i < g; ++i) {
        ll p, d;
        cin >> p >> d;
        if (d == 1)
            mx = max(mx, l - p);
        else
            mx = max(mx, p);
    }
    cout << mx << '\n';
    return 0;
}