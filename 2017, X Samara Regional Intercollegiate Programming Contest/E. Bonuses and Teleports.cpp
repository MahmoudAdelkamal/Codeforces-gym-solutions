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
#define eb emplace_back
#define endl '\n'
#define eps 1e-9
#define zero(x) (abs (x) < eps)
#define equal(a, b) (zero ((a) - (b)))

template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename A, typename B>
string to_string(pair<A, B> p);

template<typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template<typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string &s) {
  return '"' + s + '"';
}

string to_string(const char *s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first)
      res += ", ";
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template<size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++)
    res += static_cast<char>('0' + v[i]);
  return res;
}

template<typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first)
      res += ", ";
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template<typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", "
         + to_string(get<2>(p)) + ")";
}

template<typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", "
         + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() {
  cerr << endl;
}

template<typename Head, typename ... Tail>
void debug_out(Head H, Tail ... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define err(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define err(...) 42
#endif
const long long N = 2e5 + 5, NN = 1e5 * 2 + 2, mod = 1e9 + 7;

void task_h() {
  int n, m;
  cin >> n >> m;
  vector<ll> tele(n);
  vector<ll> bonus(m);
  for (int i = 0; i < n; ++i) {
    cin >> tele[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> bonus[i];
  }
  ll cur = tele[0], res = 0;
  for (int i = 0; i < m; ++i) {
    ll first = abs(cur - bonus[i]);
    ll second = 1e18, third = 1e18, fourth = 1e18;
    auto x = lower_bound(tele.begin(), tele.end(), cur);
    ll min_cur = bonus[i];
    bool ok = false;
    if (*x == cur)ok = true;
    //cur = bonus[i];
    if (x == tele.begin()) {
      second = abs(*x - cur);
      second += abs(*x - bonus[i]);
      if (first > second) {
        first = second;
        min_cur = *x;
      }
      x++;
      if (x != tele.end()) {
        if (!ok) {
          third = abs(*x - cur);
          third += abs(*x - bonus[i]);
        } else {
          third = abs(*x - bonus[i]);
        }
        if (first > third) {
          first = third;
          min_cur = *x;
        }
      }
      x--;
    } else {
      if (!ok) {
        second = abs(*x - cur);
        second += abs(*x - bonus[i]);
      } else {
        second = abs(*x - bonus[i]);
      }
      if (first > second) {
        first = second;
        min_cur = *x;
      }
      x--;
      if (!ok) {
        third = abs(*x - cur);
        third += abs(*x - bonus[i]);
      } else {
        third = abs(*x - bonus[i]);
      }
      if (first > third) {
        first = third;
        min_cur = *x;
      }
      x++;
      x++;
      if (x != tele.end()) {
        if (!ok) {
          fourth = abs(*x - cur);
          fourth += abs(*x - bonus[i]);
        } else {
          fourth = abs(*x - bonus[i]);
        }
        if (first > fourth) {
          first = fourth;
          min_cur = *x;
        }
      }
    }
    res += first;
    cur = min_cur;
  }
  cout << res << endl;
}


void task_g() {
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> v(n, vector<ll>(m));
  vector<ll> rows(n, 0), col(m, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> v[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      rows[i] += v[i][j];
    }
  }
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i) {
      col[j] += v[i][j];
    }
  }
  ll maxx = 0;
  int my_row, my_col;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (v[i][j] > maxx) {
        maxx = v[i][j];
        my_row = i;
        my_col = j;
      }
    }
  }
  maxx = 0;
  int ans1, ans2;


  for (int i = 0; i < n; ++i) {
    if (col[my_col] + rows[i] - v[i][my_col] > maxx) {
      maxx = col[my_col] + rows[i] - v[i][my_col];
      ans1 = i + 1;
      ans2 = my_col + 1;
    }
    //   cout << col[my_col] + rows[i] << " ";
  }
  //cout << endl;
  for (int i = 0; i < m; ++i) {
    if (rows[my_row] + col[i] - v[my_row][i] > maxx) {
      maxx = rows[my_row] + col[i] - v[my_row][i];
      ans1 = my_row + 1;
      ans2 = i + 1;
    }
    //  cout << rows[my_row] + col[i] << " ";

  }
  cout << ans1 << " " << ans2 << endl;
}


void task_e() {
  int n, m;
  cin >> n >> m;
  ll t[n + 5], b[m + 5], Ans = 0;
  for (int i = 0; i < n; i++)cin >> t[i];
  for (int j = 0; j < m; j++)cin >> b[j];

  for (int i = 0; i < n; i++) {
    int st = 0, ed = m - 1, mn = 1e9, diff = 0, index = 0;
    while (ed >= st) {
      int mid = (ed + st) >> 1;
      if (b[mid] >= t[i] && diff < abs(b[mid] - t[i])) {
        diff = abs(b[mid] - t[i]);
        index = mid;
        st = mid + 1;
      } else ed = mid - 1;
    }

    ll F = diff;
    cout << F << "\n";
    ll S = 1e9, th = 1e9;
    if (index - 1 >= 0)S = F + (b[index] - b[index - 1]);
    if (index + 1 < m)th = F + (b[index + 1] - b[index]);
    F *= 2;
    Ans += min({F, S, th});
  }
  cout << Ans << "\n";
}

void task_ee() {
  vector<vector<ll>> v(N);
  ll n, m, t[N], b[N];
  cin >> n >> m;
  for (ll i = 1; i <= n; i++) {
    cin >> t[i];
  }
  t[0] = -5e9;
  t[++n] = 5e9;
  n++;
  for (ll i = 0; i < n; i++) {
    v[i + 1].push_back(t[i]);
  }
  for (ll i = 0; i < m; i++) {
    cin >> b[i];
    ll idx = lower_bound(t, t + n, b[i]) - t;
    v[idx].push_back(b[i]);
  }
  ll ans = 0;
  for (ll i = 1; i < n; i++) {
    v[i].push_back(t[i]);
    ll tmp = t[i] - t[i - 1];
    for (ll j = 0; j + 1 < v[i].size(); j++) {
      tmp = min(tmp, 2LL * (v[i][j] - t[i - 1] + t[i] - v[i][j + 1]));
    }
    ans += tmp;
  }
  cout << ans << endl;
}

void task_k() {
  int n;
  cin >> n;
  vector<pair<double, int>> v;
  vector<pair<ll, pair<ll, ll>>> inp;
  for (int i = 0; i < n; ++i) {
    ll a, b, c;
    cin >> a >> b >> c;
    inp.pb({a, {b, c}});
    ll rem = b - a + 1;
    v.pb({(double) c / (double) rem, i});
  }
  sort(v.rbegin(), v.rend());
  for (int i = 0; i < v.size(); ++i) {

  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  // cin >> t;
  for (int i = 1; i <= t; ++i) {
    //task_a();
    //  task_e();
    //task_g();
    // task_d();
    //task_m();
    task_ee();
    //task_k();
  }

  return 0;
}