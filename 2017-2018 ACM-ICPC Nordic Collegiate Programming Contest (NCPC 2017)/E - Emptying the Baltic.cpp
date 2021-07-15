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
const long long N = 2005, NN = 1e5 * 2 + 2, mod = 7901;


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

void task_gggg() {
  int n, m;
  cin >> n >> m;
  map<int, pair<int, int>> mp;
  ordered_multi_set<pair<int, int>> st;
  st.insert({1e9, 1e9});
  st.insert({-1e9, -1e9});
  //mp[1] = {0, 0};
  while (m--) {
    int t, b;
    cin >> t >> b;
    if (mp[t] == make_pair(0, 0)) {
      mp[t] = {1, b};
      if (t != 1)
        st.insert(mp[t]);
    } else {
      //  cerr << t << " " << b << " a" << endl;
      pair<int, int> prev = mp[t];
      mp[t] = {prev.first + 1, prev.second + b};
      if (t != 1) {
        st.erase(st.find(prev));
        st.insert(mp[t]);
      }
    }
    int x = st.order_of_key(mp[1]);
    cerr << x << " " << st.size() << endl;
    int rem = st.size() - 2;
    rem -= (x - 1);
    cout << rem + 1 << endl;
  }
}

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
    if (mp[t] == make_pair(0, 0)) {
      mp[t] = {1, b};
      cnt[{1, b}]++;
      if (t != 1) {
        st.insert(mp[t]);
        if (fake.find({1, b}) == fake.end())
          fake.insert({1, b});
      }
    } else {
      pair<int, int> prev = mp[t];
      if (cnt[prev])
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
ll dist[N][N];
ll ans = 0;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void task_E() {
  priority_queue<pair<ll, pair<int, int>>> pq;
  int h, w, g[N][N];
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> g[i][j];
    }
  }


  int i, j;
  cin >> i >> j;

  i--, j--;
  for (int ii = 0; ii < N; ii++) {
    for (int jj = 0; jj < N; jj++) {
      dist[ii][jj] = 1e18;
    }
  }
  pq.push({-g[i][j], {i, j}});
  while (!pq.empty())
  {
    ll cost = -pq.top().first;
    ll i = pq.top().second.first;
    ll j = pq.top().second.second;
    pq.pop();
    if (cost < dist[i][j]) {
      dist[i][j] = cost;
      ans -= cost;
      for(int idx=0;idx<8;idx++)
      {
        int newx = i + dx[idx];
        int newy = j + dy[idx];
        if(g[newx][newy]>=0)
          continue;
        ll maxi = max(cost,1ll*g[newx][newy]);
        if(maxi<dist[newx][newy])
          pq.push({-maxi,{newx,newy}});
      }
    }
  }
  cout<<ans<<endl;
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
    // task_I();
    //task_g();
    //   task_D();
    task_E();
  }

  return 0;
}