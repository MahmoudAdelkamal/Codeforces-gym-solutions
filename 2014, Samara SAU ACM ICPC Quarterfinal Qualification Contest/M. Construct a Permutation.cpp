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
 
void task_g() {
  vector<ll> v;
  ll n, s;
  cin >> n >> s;
  v.push_back(1);
  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    if (1LL * v.back() * x < 1e10)
      v.push_back(v.back() * x);
    else
      break;
  }
  sort(v.rbegin(), v.rend());
  ll ans = 0;
  for (auto i:v) {
    ans += s / i;
    s %= i;
  }
  cout << ans << endl;
}
 
void task_m()
{
    vector<int>v;
    int a,b;
    cin>>a>>b;
    int n = a*b;
    cout<<n<<endl;
    for(int i=1;i<=n;i++)
       v.push_back(i);
    for(int i=n-a;i>=0;i-=a)
    {
       for(int j=i;j<i+a;j++)
         cout<<v[j]<<" ";
    }
}
void task_b() {
 
}
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  //cin >> t;
  for (int i = 1; i <= t; ++i) {
    //task_a();
    // task_b();
    //task_c();
    task_m();
  }
 
  return 0;
}