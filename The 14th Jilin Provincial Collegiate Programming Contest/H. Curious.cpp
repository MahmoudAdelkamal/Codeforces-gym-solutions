#include <bits/stdc++.h>
#define yala ios::sync_with_stdio(0); cin.tie(0); ios_base::sync_with_stdio(0);
#define RW freopen("input.txt","mirror",stdin), freopen("output.txt","w",stdout);
#define ll long long
#define ld long double
using namespace std;
const int N = 1e5 + 100;
const int MOD = 1e9;
const ll INF = 1e18;
const double pi = 3.1415926536;
const int mod = 1e9 + 7;
typedef complex<ll>point;
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};
ll arr[N], cnt[N], ans[N], b[N];
vector<int>divisors[N];
void pre_divisions() {
    for (int num = 1; num < N; ++num) {
        for (int i = 1; 1ll * i * i <= num; i++) {
            if (num % i == 0) {
                divisors[num].push_back(i);
                if (i != num / i)
                    divisors[num].push_back(num / i);
            }
        }
    }
}
void solve(int n) {
    for (int i = 0; i < n; ++i) {
        for (auto &div: divisors[arr[i]]) {
            cnt[div]++;
        }
    }
    for (int i = 1e5; i >= 1; --i) {
        ans[i] = (cnt[i] * cnt[i]*1ll) - (b[i]);
        for (auto &div:divisors[i]) {
            if (i != div)
                b[div] += ans[i];
        }
    }
}
void clr() {
    memset(arr, 0, sizeof arr);
    memset(cnt, 0, sizeof cnt);
    memset(ans, 0, sizeof ans);
    memset(b, 0, sizeof b);
}
int main() {
    yala;
    pre_divisions();
    int t;
    cin >> t;
    while (t--) {
        clr();
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        solve(n);
        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            cout << ans[x] << '\n';
        }
    }
    return 0;
}