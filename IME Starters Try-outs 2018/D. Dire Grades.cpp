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
const long long N = 1e5 + 9, NN = 1e5 * 2 + 2, mod = 1e9 + 7;

void task_a() {
  int n;
  cin >> n;
  vector<ll> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  ll cnt = 0, res = 0;
  for (int i = 0; i < n; ++i) {
    if (v[i] > 0)cnt += v[i];
    else {
      if (cnt + v[i] >= 0)cnt += v[i];
      else {
        res += abs(v[i]) - cnt;
        cnt = 0;
      }
    }
  }
  cout << res << endl;
}

void b() {

}

void c() {

}

double seg[N << 2], a[N];

struct segtree {
    void build(int p, int l, int r) {
      if (l == r)return void(seg[p] = a[l]);
      int m = (l + r) >> 1;
      build(p << 1, l, m);
      build(p << 1 | 1, m + 1, r);
      seg[p] = seg[p << 1] + seg[p << 1 | 1];
    }

    void update(int p, int l, int r, int i, double v) {
      if (l == r)return void(seg[p] = v);
      int m = (l + r) >> 1;
      if (m >= i)update(p << 1, l, m, i, v);
      else update(p << 1 | 1, m + 1, r, i, v);
      seg[p] = seg[p << 1] + seg[p << 1 | 1];
    }

    double query(int p, int l, int r, int a, int b) {
      if (a > r || l > b)return 0;
      if (l >= a && b >= r)return seg[p];
      int m = (l + r) >> 1;
      return query(p << 1, l, m, a, b) + query(p << 1 | 1, m + 1, r, a, b);
    }

};

void d() {

  int n;
  cin >> n;
  segtree t;
  for (int i = 0; i < n; i++)cin >> a[i];
  int q;
  cin >> q;
  t.build(1, 0, n - 1);
  while (q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int i;
      double val;
      cin >> i >> val;
      i--;
      t.update(1, 0, n - 1, i, val);
    } else {
      int l, r;
      cin >> l >> r;
      --l, --r;
      double Ans = (t.query(1, 0, n - 1, l, r));
      cout << fixed << setprecision(8);
      cout << ((Ans) * 1.0 / (r - l + 1)) * 1.0 << "\n";
    }
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
    d();
    //task_b();
    //task_c();
    //task_d();
  }

  return 0;
}