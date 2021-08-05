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
const long long N = 2e5 + 5, NN = 1e7 + 5, mod = 1e9 + 7;
ll Ans = 0;
ll n, h, st[N], en[N], acc[N];

void task_b() {
  cin >> n >> h;
  for (int i = 0; i < n; i++) {
    cin >> st[i] >> en[i];
    if (i)
      acc[i] = st[i] - en[i - 1] + acc[i - 1];
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int low = 0, high = n - 1, m = -1;
    while (low <= high) {
      int mid = (low + high) / 2;
      if (acc[mid] - acc[i] < h) {
        m = mid;
        low = mid + 1;
      } else
        high = mid - 1;
    }
    ll rem = h - (acc[m] - acc[i]);
    ans = max(ans, en[m] - st[i] + rem);

  }
  cout << ans << endl;
}


ll seg[N << 2], arr[N], mn[N << 2], Lazy[N << 2], mx[N << 2];

struct segtree {
    void build(int p, int l, int r) {
      if (l == r)return void(seg[p] = mn[p] = mx[p] = arr[l]);
      int m = (l + r) >> 1;
      build(p << 1, l, m);
      build(p << 1 | 1, m + 1, r);
      mn[p] = min(mn[p << 1], mn[p << 1 | 1]);
      mx[p] = max(mx[p << 1], mx[p << 1 | 1]);

    }

    void push(int p) {
      if (Lazy[p] == 0)return;
      seg[p << 1] = Lazy[p];
      seg[p << 1 | 1] = Lazy[p];
      mn[p << 1] = min(Lazy[p], mn[p << 1]);
      mn[p << 1 | 1] = min(Lazy[p], mn[p << 1 | 1]);
      mx[p << 1] = max(Lazy[p], mx[p << 1]);
      mx[p << 1 | 1] = max(Lazy[p], mx[p << 1 | 1]);
      Lazy[p << 1] = Lazy[p];
      Lazy[p << 1 | 1] = Lazy[p];
      Lazy[p] = 0;
    }

    void update(int p, int l, int r, int a, int b, int val) {
      if (l > b || r < a)return;
      if (l <= a && b <= r) {
        mn[p] = val;
        mx[p] = val;
        Lazy[p] = val;
        seg[p] = val;
        return;
      }
      push(p);
      int m = (l + r) >> 1;
      update(p << 1, l, m, a, b, val);
      update(p << 1 | 1, m + 1, r, a, b, val);
      mn[p] = min(mn[p << 1], mn[p << 1 | 1]);
      mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
    }

    ll get_prefix(int p, int l, int r, ll val) {
      if (l == r)return (seg[p] == val) ? l : -1;
      push(p);
      int m = (l + r) >> 1;
      if (mn[p << 1] <= val && val <= mx[p << 1])return get_prefix(p << 1, l, m, val);
      else return get_prefix(p << 1 | 1, m + 1, r, val);
    }

    ll get_suffix(int p, int l, int r, ll val) {
      if (l == r)return (seg[p] == val) ? l : -1;
      int m = (l + r) >> 1;
      push(p);
      if (mn[p << 1 | 1] <= val && val <= mx[p << 1 | 1])return get_suffix(p << 1 | 1, m + 1, r, val);
      else return get_suffix(p << 1, l, m, val);
    }

    ll query(int p, int l, int r, int k) {
      if (l == r)return (seg[p]);
      push(p);
      int m = (l + r) >> 1;
      if (m >= k)query(p << 1, l, m, k);
      else query(p << 1 | 1, m + 1, r, k);
    }

};

void task_e() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  segtree t;
  t.build(1, 0, n - 1);
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    ll pre = t.get_prefix(1, 0, n - 1, x);
    ll suff = t.get_suffix(1, 0, n - 1, x);
    if (pre == -1 || suff == -1)continue;
    t.update(1, 0, n - 1, pre, suff, x);
  }
  for (int i = 0; i < n; i++)cout << t.query(1, 0, n - 1, i) << " ";
}


void g() {
  int n;
  cin >> n;
  set<int> st;
  for (int i = 0; i < n; ++i) {
    st.insert(i + 1);
  }
  vector<pair<pair<int, int>, int>> v;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    v.pb({{a, b}, i});
    if (v[i].first.first > v[i].first.second)swap(v[i].first.first, v[i].first.second);
  }
  for (int i = 0; i < n - 1; ++i) {
    if (max(v[i].first.first, v[i].first.second) != n) {
      cout << "NO\n";
      return;
    }
  }

  sort(v.begin(), v.end());
  int maxx = 0;
  vector<int> ans;
  for (int i = 0; i < n - 1; ++i) {
    if (v[i].first.first > maxx) {
      maxx = v[i].first.first;
      ans.pb(v[i].first.first);
      st.erase(v[i].first.first);
    } else {
      ans.pb(*st.begin());
      st.erase(st.begin());
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    if (ans[i] > v[i].first.first) {
      cout << "NO\n";
      return;
    }
  }
  ans.pb(n);
  cout << "YES\n";
  vector<pair<int, int>> final(n);
  for (int i = 0; i < n - 1; ++i) {
    final[v[i].second] = {ans[i], ans[i + 1]};
  }
  for (int i = 0; i < n - 1; ++i) {
    cout << final[i].first << " " << final[i].second << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  //cin >> t;
  for (int i = 1; i <= t; ++i) {
    //task_D();
    //  task_e();
    //task_c();
    //task_J();
    g();
  }
  return 0;
}