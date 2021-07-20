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
const long long N = 1e5+5, NN = 1e5 * 2 + 2, mod = 1e9 + 7;
int par[N],sz[N];
void init()
{
  for(int i=0;i<N;i++)
     par[i] = i,sz[i] = 1;
}
int Find(int u)
{
  if(u==par[u])
    return u;
  return par[u] = Find(par[u]);
}
void connect(int u,int v)
{
   u = Find(u);
   v = Find(v);
   if(u==v)
     return;
   if(sz[u]<sz[v])
   {
      sz[v]+=sz[u];
      par[u] = v;
   }
   else
   {
     sz[u]+=sz[v];
     par[v] = u;
   }
}
bool is_con(int u,int v)
{
   u = Find(u);
   v = Find(v);
   return (u==v);
}
vector<vector<int>>adj(N);
bool vis[N];
int p[N];
void dfs(int node,int par)
{
   if(vis[node])
     return;
   vis[node] = 1;
   p[node] = par;
   for(int i=0;i<adj[node].size();i++)
   {
      int child = adj[node][i];
      if(!vis[child])
        dfs(child,node);
   }
}
void task_e()
{
    init();
    vector<pair<int,pair<int,int>>>v;
    int n,ans =0 ;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
      for(int j=1;j<i;j++)
      {
         int x;
         cin>>x;
         v.push_back({x,{i,j}});
      }
    }
    sort(v.rbegin(),v.rend());
    for(int i=0;i<v.size();i++)
    {
       int u = v[i].second.first;
       int V = v[i].second.second;
       if(!is_con(u,V))
       {
          connect(u,V);
          adj[u].push_back(V);
          adj[V].push_back(u);
          ans+=v[i].first;
       }
    }
    dfs(1,-1);
    cout<<ans<<endl;
    for(int i=2;i<=n;i++)
      cout<<p[i]<<endl;
}




int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  // cin >> t;
  for (int i = 1; i <= t; ++i) {
    task_e();
    //task_b();
    //task_f();
    //task_d();
  }

  return 0;
}