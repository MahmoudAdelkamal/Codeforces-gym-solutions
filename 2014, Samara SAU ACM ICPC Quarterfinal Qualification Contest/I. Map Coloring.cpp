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
//#define endl '\n'
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
const long long N = 1e5 + 5, NN = 1e5 * 2 + 2, mod = 1e9 + 7;
int color[N];
int freq[N];
int n,m,k;
vector<vector<int>>adj(N);
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
void dfs(int node)
{
   set<int>st;
   for(auto i:adj[node])
   {
      if(color[i]!=-1)
          st.insert(color[i]);
   }
   if(st.size()>=k)
   {
      cout<<-1<<endl;
      exit(0);
   }
   int c = 1;
   for(auto i:st)
   {
     if(i==c)
       c++;
     else
       break;
   }
   freq[c]++;
   color[node] = c;
   for(auto i:adj[node])
   {
     if(color[i]==-1)
        dfs(i);
   }
}
void task_m()
{
    cin>>n>>m>>k;
    while(m--)
    {
       int u,v;
       cin>>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    memset(color,-1,sizeof(color));
    for(int i=1;i<=n;i++)
    {
      if(color[i]==-1)
        color[i] = 1,dfs(i);
    }
    for(int i=1;i<=n;i++)
    {
       int sz = adj[i].size();
       if(n-freq[color[i]]-sz>0)
       {
         cout<<-1<<endl;
         return;
       }
    }
    for(int i=1;i<=n;i++)
      cout<<color[i]<<" ";
  }
 
void task_c() {
  int n = 1e4;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if ((i + j) * 10 == i * j)cout << i << " " << j << "\n";
    }
  }
  cout << "----------------------\n";
  int k;
  cin >> k;
  set<double> st, v;
  for (int i = 1; i * i <= k; i++) {
    if (k % i == 0) {
      st.insert(i);
      v.insert(i);
      if (i * i != k) {
        st.insert(k / i);
        v.insert(k / i);
      }
    }
  }
  for (auto x : st) {
    for (auto z : st) {
      if (x == z)continue;
      if (x/z > 1)v.insert(x / z);
    }
  }
 
 
 
  for (auto y : v)cout << y << " ";
  cout << "--------------\n";
 
 
  for (ll i = k + 1; i < 1e7; i++) {
    if (i * k % abs(i - k) == 0) {
      cout << i << " " << (i * k) / abs(i - k) << " ";
      cout << (1.0 * ((i * k) / abs(i - k)) / i) << "\n";
    }
  }
}
 
 
 
 
void task_I() {
 
}
vector<int> ask(int l , int r)
{
  cout << "Q " << l << " "<< r << endl;
  vector<int> v;
  for (int i=0;i<r-l+1;i++) {
   int al;
   cin >> al;
    v.push_back(al);
  }
  return v;
}
void task_B()
{
  int n;
  cin >> n;
  vector<vector<int>> vec;
  int Moves = ((n+1)/2)-1;
  set<int> st;
  for (int i=1;i<=n;i++)st.insert(i);
  for (int i=0;i<n/2;i++)
  {
   vec.push_back(ask(i+2,i+2+Moves));
  }
  ll Index[109]={};
 
  for (int i=0;i<vec.size();i++)
  {
    for (auto x : vec[i])st.erase(x);
    if (i+1 < vec.size())
    {
      auto x = vec[i] , z = vec[i+1];
      for (int j=0;j<vec[i].size();j++)
      {
        if (x[j] != z[j]) {
          Index[i + 2] = x[j];
          Index[i + 2 + Moves + 1] = z[j];
        }
      }
    }
  }
  Index[1] = *st.begin();
  st.clear();
  for (int i=1;i<=100;i++)st.insert(i);
  for (int i=1;i<=100;i++)
  {
   if (Index[i] != 0)st.erase(Index[i]);
  }
  Index[2+Moves] = *st.begin();
  cout << "A ";
  for (int i=1;i<=n;i++)cout << Index[i] << " ";
 
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
    task_m();
    //   task_k();
  }
 
  return 0;
}