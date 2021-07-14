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
const long long N = 1e5 * 2 + 5, NN = 1e5 * 2 + 2, mod = 7901;

void task_a() {
  int q;
  cin >> q;
  while (q--) {
    ll R, r;
    cin >> R >> r;
    if (R * R > 2 * r * r)cout << "1\n";
    else cout << "2\n";
  }

}

void task_b() {


}

void task_c() {

  string a, b;
  cin >> a >> b;
  bool ok = 1;
  int n = a.size(), Cost = 0;
  for (int i = 0; i <= n - i - 1; i++) {
    if (ok) {
      if (a[i] == b[i] && a[n - 1 - i] == b[n - 1 - i])continue;
      else if (a[i] == b[n - 1 - i] && b[i] == a[n - 1 - i])Cost++, ok = 0;
      else {
        cout << "-1\n";
        return;
      }
    } else {
      if (a[i] == b[n - 1 - i] && b[i] == a[n - 1 - i])continue;
      if (a[i] == b[i] && a[n - 1 - i] == b[n - 1 - i])Cost++, ok = 1;
      else {
        cout << "-1\n";
        return;
      }
    }
  }
  cout << Cost << "\n";

}

void task_d() {}

void task_j() {

  int l[2], r[N], p[2], d[2], k, ans = 0;
  for (int i = 0; i < 2; i++) {
    cin >> l[i] >> r[i] >> p[i] >> d[i];
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    if (p[0] == p[1])
      ans++;
    for (int j = 0; j < 2; j++) {
      // left
      if (d[j] == 0) {
        if (p[j] == l[j])
          d[j] = !d[j], p[j]++;
        else
          p[j]--;
      }
        // right
      else {
        if (p[j] == r[j])
          d[j] = !d[j], p[j]--;
        else
          p[j]++;
      }
    }
  }
  if (p[0] == p[1])
    ans++;
  cout << ans << endl;
}

ll fp(ll base, ll exp) {
  if (exp == 0)
    return 1;
  ll ans = fp(base, exp / 2);
  ans = (ans * ans) % mod;
  if (exp % 2 != 0)
    ans = (ans * (base % mod)) % mod;
  return ans;
}

ll fact[1010];

void calcFacAndInv(ll n) {
  fact[0] = 1;
  for (ll i = 1; i <= n; i++) {
    fact[i] = (i * fact[i - 1]) % mod;
  }
}

void task_f() {
  int n;
  cin >> n;
  vector<int> v(n);
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    mp[a]++;
  }
  calcFacAndInv(1009);
  ll res = 1;
  for (auto i : mp) {
    res = ((res % mod) * fact[i.second]) % mod;
  }
  cout << res << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    //task_a();
    //task_b();
    task_c();
    //task_d();
    //task_j();
    //  task_f();
  }

  return 0;
}