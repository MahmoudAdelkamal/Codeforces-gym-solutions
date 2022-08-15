#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'
#define pq priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
#define graph1 vector<vector<pair<ll,ll>>>
#define graph vector<vector<ll>>
#define pq1 priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll,ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define fastVictory ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int cnt[N], a[N];

void add(int a, int b) {
    if (a > b)swap(a, b);
    cnt[a]++;
    cnt[b + 1]--;
}

int main() {
    fastVictory
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
            a[i]--;
        }
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            int y = a[i] + x;
            if (y >= n) {
                add(a[i], n - 1);
                add(0, y - n);
            } else if (y < 0) {
                add(0, a[i]);
                add(y + n, n - 1);
            } else add(a[i], y);
        }
        for (int i = 1; i < n; i++)
            cnt[i] += cnt[i - 1];
        int mx = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (cnt[i] > mx) {
                mx = cnt[i];
                ans = i + 1;
            }
        }
        cout << ans << " " << mx << endl;


    }
}