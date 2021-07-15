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
const long long N = 505, NN = 1e5 * 2 + 2, mod = 7901;


void task_a() {
  int a, b;
  cin >> a >> b;
  if (a == b) {
    if (a + b > 0)
      cout << "Even " << a + b << endl;
    else {
      cout << "Not a moose\n";
    }
  } else {
    if (max(a, b) * 2 > 0)
      cout << "Odd " << max(a, b) * 2 << endl;
    else {
      cout << "Not a moose\n";
    }
  }
}

struct player {
    string name;
    double a, b;

    bool operator<(player other) const {
      return b < other.b;
    }
};

void task_b() {
  int n;
  cin >> n;
  vector<player> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].name >> p[i].a >> p[i].b;
  }
  sort(p.begin(), p.end());
  int mxi = -1;
  double mx = INT_MAX;
  for (int i = 0; i < n; i++) {
    double cur = p[i].a;
    if (i <= 2)
      cur += p[3].b, cur -= p[i].b;
    for (int j = 0; j < 3; j++)
      cur += p[j].b;
    if (cur < mx)
      mx = cur, mxi = i;
  }
  cout << fixed << setprecision(6) << mx << endl;
  cout << p[mxi].name << endl;
  int ans = 3;
  for (int i = 0; i < ans; i++) {
    if (i == mxi)
      ans++;
    else
      cout << p[i].name << endl;
  }
}

struct compare {
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
      if (a.first == b.first) {
        return a.second > b.second;
      } else
        return a.first < b.first;
    }
};

template<typename T> using ordered_multi_set = tree<pair<int, int>, null_type, compare, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_set = tree<pair<int, int>, null_type, compare, rb_tree_tag, tree_order_statistics_node_update>;

void task_g() {
  int n, m;
  cin >> n >> m;
  map<int, pair<int, int>> mp;
  ordered_multi_set<pair<int, int>> st;
  st.insert({1e9, 1e9});
  st.insert({-1e9, -1e9});
  ordered_set<pair<int, int >> fake;
  fake.insert({1e9, 1e9});
  fake.insert({-1e9, -1e9});
  map<pair<int, int>, int> cnt;
  while (m--) {
    int t, b;
    cin >> t >> b;
    if (!mp.count(t)) {
      mp[t] = {1, b};
      cnt[{1, b}]++;
      if (t != 1) {
        st.insert(mp[t]);
        if (fake.find({1, b}) == fake.end())
          fake.insert({1, b});
      }
    } else {
      pair<int, int> prev = mp[t];
      cnt[prev]--;
      if (cnt[prev] == 0)fake.erase(prev);
      mp[t] = {prev.first + 1, prev.second + b};
      cnt[mp[t]]++;
      if (t != 1) {
        st.erase(st.find(prev));
        st.insert(mp[t]);
        if (fake.find(mp[t]) == fake.end())
          fake.insert(mp[t]);
      }
    }
    /* int x = st.order_of_key(mp[1]);
     int rem = st.size() - 2;
     rem -= (x - 1);
     int distinct = fake.order_of_key(mp[1]);
     if (*(st.find_by_order(x)) != mp[1]) {
       cout << rem + 1 << endl;
     } else {
       rem -= cnt[mp[1]] - 1;
     }*/
    int dis = fake.order_of_key(mp[1]);
    if (*(fake.find_by_order(dis)) == mp[1]) {
      int size = fake.size() - 2;
      size -= dis;
      size++;
      cout << size << endl;
    } else {
      int size = fake.size() - 2;
      size -= dis;
      size++;
      cout << size + 1 << endl;
    }
  }
}

int par[N];
string name[N];
vector<vector<int>> adj(N);

int bfs(int src) {
  queue<int> q;
  int dist[N], ans = INT_MAX;
  for (int i = 0; i < N; i++)
    dist[i] = -1;
  q.push(src);
  dist[src] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for(int v:adj[u])
    {
        if(v==src)
        {
          ans = min(ans,dist[u]+1);
        }
        if(dist[v]==-1)
        {
           dist[v] = dist[u]+1;
           q.push(v);
        }
    }
  }
  return ans;
}

int bfs2(int src) {
  queue<int> q;
  int dist[N], ans = INT_MAX;
  for (int i = 0; i < N; i++)
    dist[i] = -1,par[i] = -1;
  q.push(src);
  dist[src] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if (v == src)
        return u;
      if (dist[v] == -1) {
        dist[v] = dist[u] + 1;
        par[v] = u;
        q.push(v);
      }
    }
  }
  return -1;
}

void print(int u) {
  if (par[u] == -1) {
    cout << name[u] << " ";
    return;
  }
  print(par[u]);
  cout << name[u] << " ";

}

void task_I() {
  map<string, int> mp;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> name[i];
    mp[name[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    int k;
    string s;
    cin >> s >> k;
    cin.ignore();
    for (int j = 0; j < k; j++) {
      string s2;
      getline(cin, s2);
      int idx = 7;
      string cur = "";
      for (int z = idx; z < s2.size(); z++) {
        if (s2[z] == ' ')
          continue;
        if (s2[z] == ',') {
          adj[mp[s]].push_back(mp[cur]);
          cur = "";
          continue;
        }
        cur += s2[z];
      }
      if (cur != "")
        adj[mp[s]].push_back(mp[cur]);
    }
  }
  int mx = INT_MAX, idx = 0;
  for (int i = 0; i < n; i++) {
    int tmp = bfs(i);
    //cout << tmp << "\n";
    if (tmp < mx) {
      mx = tmp;
      idx = i;
    }
  }
  if(mx>=INT_MAX)
    cout<<"SHIP IT"<<endl;
  else
    print(bfs2(idx));
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  //cin >> t;
  for (int i = 1; i <= t; ++i) {
    //task_b();
    task_I();
    //task_g();
    //   task_D();
  }

  return 0;
}