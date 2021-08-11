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
const long long N = 2e5 + 5, NN = 1e4 * 8 + 2, mod = 1e9 + 7;

void task_a() {
  ll a, b, n;
  cin >> a >> b >> n;
  ll tmp = (n - a + b - a - 1) / (b - a);
  cout << 2 * tmp - 1;
}

void task_b() {

}

void task_c() {

}

void task_d() {

}

int n,a[N];
unordered_map<int, int> mp;

void m()
{
  ll Ans = 0;
  mp.clear();
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    mp[a[i]]++;
  }
  for(int i=0;i<n;i++)
  {
    mp[a[i]]--;
    for (int j = i-1; j>=0; j--)
    {
      int val = 2*a[i]-a[j];
      if(mp.count(val))
        Ans+=mp[val];
    }
  }
  printf("%lld\n", Ans);
}

map<int, vector<int>> dis;

vector<vector<int>> v(N);

void dfs(int node, int cnt, int prev = -1) {
  dis[cnt].pb(node);
  for (auto i : v[node]) {
    if (i != prev) {
      dfs(i, cnt + 1, node);
    }
  }
}

void e() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n - 1; ++i) {
    int c, b;
    cin >> c >> b;
    v[c].pb(b);
    v[b].pb(c);
  }
  map<int, bool> check;
  int c;
  for (int i = 0; i < m; ++i) {
    cin >> c;
    check[c] = 1;
  }
  dfs(c, 0);
  for (int i = 0; i <= n; ++i) {
    if (dis[i].empty())continue;
    int cnt = 0, node;
    for (auto y : dis[i]) {
      if (check[y])cnt++, node = y;
    }
    if (dis[i * 2].empty())continue;
    for (auto y : dis[i * 2]) {
      if (check[y])cnt++;
    }
    cout << i << " " << cnt << endl;
    if (cnt == m) {
      cout << "YES\n";
      cout << node << endl;
      return;
    }
  }
  cout << "NO\n";
}

int main() {
//  ios_base::sync_with_stdio(0);
  // cin.tie(0);
  //cout.tie(0);
  int t;
  t = 1;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
   // e();
     m();
    //task_b();
    //task_c();
    //task_d();
  }
  return 0;
}