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
const ll N = 805, NN = 1e4 * 8 + 2, mod = 1e9 + 7;

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
            if (npr(i, j) == 209728) {
                cout << "y";
            }
        }
    }
    cout << npr(16, 5) - (209728);
    // cout << npr(16, 4);
}

struct Point {
    int x, y, indx;

    Point(int x, int y, int indx) {
        this->x = x;
        this->y = y;
        this->indx = indx;
    }
};

bool compare(const Point &a, const Point &b) {
    if (a.y == b.y) {
        return a.x < b.x;
    }
    return a.y < b.y;
}
void f(){



}

void g() {
    int n;
    cin >> n;
    vector<Point> v;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        v.pb(Point(a, b, i));
    }
    sort(v.begin(), v.end(), compare);
    map<int, vector<pair<int, int>>> mp;
    for (int i = 0; i < n; ++i) {
        mp[v[i].y].pb({v[i].x, v[i].indx});
    }
    int cnt = 0;
    vector<int> test;
    int prev;
    for (auto i : mp) {
        if (!test.empty() and test.size() == i.second.size()) {
            vector<int> fake;
            for (int j = 0; j < i.second.size(); ++j) {
                fake.pb(i.second[j].first);
            }
            if (fake == test) {
                if (abs(prev - i.first - 1) > 0)
                    cnt *= abs(prev - i.first - 1);
            }
        }
        prev = i.first;
        test.clear();
        for (int j = 0; j < i.second.size(); ++j) {
            if (j == i.second.size() - 1) {
                if (abs(i.second[j].second - i.second[0].second) == 1) {
                    cnt += abs(i.second[j].first - i.second[0].first - 1);
                }
            } else if (abs(i.second[j].second - i.second[j + 1].second) == 1) {
                if (abs(i.second[j].first - i.second[j].first - 1) > 0)
                    cnt += abs(i.second[j].first - i.second[j].first - 1);
            }
            test.pb(i.second[j].first);
        }
    }
    cout << cnt << endl;
}
long double dist[810][810];
void E() {

    int N, m;
    cin >> N >> m;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dist[i][j] = INT_MIN;
        }
    }
    int u,v;
    double c;
    for (int i = 0; i < m; ++i) {

        cin >> u >> v >> c;
        u--, v--;
        //c*=10000;
        dist[u][v] = fmax(dist[u][v], log(c));
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                dist[i][j] = fmax(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    bool ok = 1;
    for (int i = 0; i < N; i++)
        ok &= dist[i][i] < 0;
    if (ok)
        cout << "admissible" << endl;
    else
        cout << "inadmissible" << endl;

}

void b() {
    int n, m, c;
    cin >> n >> m >> c;
    ll v = n * n * m;


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    for (int i = 1; i <= t; ++i) {
         E();
        //g();
    }
    return 0;
}