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
const long long N = 1e7 * 4 + 9, NN = 25, mod = 1e9 + 7;

void task_a() {
  ll arr[5] = {};
  for (int i = 0; i < 3; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + 3);
  ll Inc = arr[1] - arr[0];
  arr[0] += Inc;
  arr[2] += Inc;
  cout << arr[2] - arr[0] + Inc << "\n";

}

void task_b() {
  int n, m, s;
  cin >> n >> m >> s;
  int am, l, r;
  vector<int> pos[N];
  vector<int> neg[N];
  for (int i = 0; i < n; i++) {
    cin >> am >> l >> r;
    if (am > 0)
      pos[r].push_back(am);
    else
      neg[l].push_back(am);
  }
  bool flag = 0;
  ll ans = s;
  for (int i = 1; i <= m; i++) {
    auto v = neg[i];
    auto v2 = pos[i];
    for (auto it:v)
      ans += it;
    if (ans < 0)
      flag = 1;
    for (auto it:v2)
      ans += it;
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

void task_c() {}

void task_d() {}

void task_e() {

  ll n, arr[50],ans[50],cur = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  for(int i=0;i<n;i++)
  {
     if(arr[i]==0)
       ans[i] = (1LL<<cur),cur++;
  }
  for(int i=0;i<n;i++)
  {
    if(arr[i]==-1)
      ans[i] = -(1LL<<cur),cur++;
  }
  for(int i=0;i<n;i++)
  {
    if(arr[i]==1)
      ans[i] = (1LL<<cur),cur++;
  }
  ll m = 0;
  for(int i=0;i<n;i++)
     m+=ans[i]*arr[i];
  cout<<m<<endl;
  for(int i=0;i<n;i++)
    cout<<ans[i]<<" ";


}

void task_f() {}

void task_g() {
  ll n, m;
  cin >> n >> m;
  vector<ll> v(n);
  map<ll, int> check;
  bool ok = false;
  ll final = 0;
  int op1, op2;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    if (check[v[i]] && !ok) {
      ok = true;
      op1 = check[v[i]];
      op2 = i + 1;
    }
    check[v[i]] = i + 1;
    final += v[i];
  }
  if (ok) {
    cout << 1 << endl;
    cout << op1 << endl << 1 << endl << op2 << endl;
    return;
  }
  vector<vector<int>> indx(N);
  for (int i = 0; i < (1LL << n); ++i) {
    ll sum = 0;
    vector<int> pos;
    for (int j = 0; j < n; ++j) {
      if (i & (1LL << j)) {
        sum += v[j];
        pos.eb(j + 1);
      }
    }
    if (!indx[sum % m].empty()) {
      cout << indx[sum % m].size() << endl;
      for (auto y : indx[sum % m]) {
        cout << y << " ";
      }
      cout << endl;
      cout << pos.size() << endl;
      for (auto y : pos) {
        cout << y << " ";
      }
      cout << endl;
      return;
    } else {
      indx[sum % m] = pos;
    }
  }
  if (!indx[0].empty()) {
    cout << indx[0].size() << endl;
    for (auto y : indx[0]) {
      cout << y << " ";
    }
    cout << endl;
    cout << 0 << endl;
  } else
    cout << -1 << endl;
}


void task_I() {

  ll n;
  cin >> n;
  vector<int> v[n + 5];
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a].pb(b);
    v[a].pb(c);
    v[c].pb(b);
    v[c].pb(a);
    v[b].pb(a);
    v[b].pb(c);
  }
  vector<bool> ok(n + 5, 0);
  int start = 1;
  for (int i = 0; i < n; i++) {
    cout << start << " ";
    ok[start] = 1;
    ll mx = 0;
    map<int, int> mp;
    for (auto x : v[start]) {
      if (ok[x])continue;
      mp[x]++;
      if (mp[x] > mx) {
        mx = mp[x];
        start = x;
      }
    }
  }
}

void task_J() {}


int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  //cin >> t;
  for (int i = 1; i <= t; ++i) {
    //task_a();
    //task_b();
    // task_c();
    //task_d();
    task_e();
  }

  return 0;
}