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

ll sp[N][22], CostVal[N], vis[N];
vector<pair<int, int>> adj[N];

void build(int n) {
  for (int i = 1; i < 20; i++) {
    for (int j = 0; j <= n; j++) {
      sp[j][i] = sp[sp[j][i - 1]][i - 1];
    }
  }
}

vector<ll> cost(N);

void dik(ll anode, int n) {
  priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>, greater<pair<ll, pair<ll, ll>>>> q;
  vector<bool> vis(N, 0);
  for (int i = 1; i <= n; i++)
    cost[i] = 1e18;
  cost[anode] = 0;
  // cost , node;
  q.push({0, {anode, 0}});
  while (q.size()) {
    ll node = q.top().second.first;
    ll parent = q.top().second.second;
    ll costt = q.top().first;
    q.pop();
    if (vis[node])
      continue;
    sp[node][0] = parent;
    vis[node] = true;
    for (auto i : adj[node]) {
      int child = i.first;
      if (!vis[child]) {
        if (costt + i.second < cost[child]) {
          cost[child] = i.second + costt;
          q.push({cost[child], {child, node}});
        }
      }
    }
  }
}

/*void dfs(int node, int par, ll cost) {
  if (vis[node])return;
  cout << node << " " << cost << "\n";
  sp[node][0] = par;
  CostVal[node] = cost;
  vis[node] = 1;
  for (auto i : adj[node]) {
    dfs(i.first, node, cost + i.second);
  }
}*/


ll lca(ll a, ll b) {
  if (a > b)swap(b, a);
  ll dis = (b - a);
  for (int j = 20; j >= 0; j--) {
    if ((1 << j) > dis)continue;
    b = sp[b][j];
  }
//  cout << a << " " << b << "\n";
  if (a == b)return a;

  for (int j = 0; j <= 20; j++) {
    if (sp[a][j] != sp[b][j]) {
      a = sp[a][j];
      b = sp[b][j];
    }
  }
  return sp[a][0];
}

ll dist(ll a, ll b) {
  //   cout << [b] << " "<< CostVal[a] << " " ;
  cout << lca(a, b) << "\n";
  return cost[b] + cost[a] - 2 * cost[lca(a, b)];
}

void task_k() {

  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    adj[u].push_back({v, c});
    adj[v].push_back({u, c});
  }
  dik(1, n);
  build(n);
  cout << cost[4] << " " << cost[5] << " " << cost[3] << "\n";
  while (q--) {
    int u, v;
    cin >> u >> v;
    lca(u, v);
    cout << sp[u][0] << " " << sp[v][0] << "\n ";
    cout << dist(u, v) << "\n";
  }

}

ll Lcm(ll a, ll b) {
  return a / __gcd(a, b) * b;
}

void task_g() {
  ll n, x, y, a[N], ans = 0;
  cin >> n >> x >> y;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (y % x)
    cout << -1 << endl;
  else if (n == 1) {
    if (x != y)
      cout << -1 << endl;
    else {
      if (a[0] == x)
        cout << 0 << endl;
      else
        cout << 1 << endl;
    }
  } else {
    ll g = 0;
    ll l = 1;
    for (int i = 0; i < n; i++) {
      if (y%a[i] == 0 && a[i]%x == 0) {
        g = __gcd(g, a[i]);
        l = Lcm(l, a[i]);
      } else
        ans++;
    }
    ll ans2 = 0;
    if (g != x)
      ans2++;
    if (l != y)
      ans2++;
    if (ans2 && x == y)
      ans2 = 1;
    cout << max(ans, ans2) << endl;
  }


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
    //task_d();
    //task_k();
    task_g();
  }

  return 0;
}