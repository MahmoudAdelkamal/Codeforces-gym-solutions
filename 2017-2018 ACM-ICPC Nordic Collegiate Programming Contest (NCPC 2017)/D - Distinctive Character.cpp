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
      if (a.first == b.first and a.second == b.second) {

      } else if (a.first == b.first) {
        return a.second > b.second;
      } else
        return a.first < b.first;
    }
};

template<typename T> using ordered_multi_set = tree<pair<int, int>, null_type, compare, rb_tree_tag, tree_order_statistics_node_update>;

void task_g() {
  int n, m;
  cin >> n >> m;
  map<int, pair<int, int>> mp;
  ordered_multi_set<pair<int, int>> st;
  st.insert({1e9, 1e9});
  st.insert({-1e9, -1e9});
  while (m--) {
    int t, b;
    cin >> t >> b;
    if (!mp.count(t)) {
      mp[t] = {1, b};
      if (t != 1)
        st.insert(mp[t]);
    } else {
      pair<int, int> prev = mp[t];
      mp[t] = {prev.first + 1, prev.second + b};
      if (t != 1) {
        st.erase(st.find(prev));
        st.insert(mp[t]);
      }
    }

    const pair<int, int> c = mp[1];
    int x = st.order_of_key({c.first, c.second});
    int rem = st.size() - 2;
    rem -= (x - 1);
    cout << rem + 1 << endl;
  }
}
int flip(int n,int idx)
{
  return (n^(1LL<<idx));
}
void task_D()
{
    queue<int>q;
    int n,k;
    cin>>n>>k;
    int dist[(1LL<<k)+5];
    for(int i=0;i<1LL<<k;i++)
    {
       dist[i] = INT_MAX;
    }
    for(int i=0;i<n;i++)
    {
       string s;
       cin>>s;
       int tmp = 0;
       for(int j=0;j<s.size();j++)
       {
          if(s[j]=='1')
            tmp+=1LL<<j;
       }
       dist[tmp] = 0;
       q.push(tmp);
    }
    int ans = -1;
    while(!q.empty())
    {
        ans = q.front();
        q.pop();
        for(int j=0;j<k;j++)
        {
           int tmp = flip(ans,j);
           if(dist[ans]+1<dist[tmp])
           {
              dist[tmp] = dist[ans]+1;
              q.push(tmp);
           }
        }
    }
    for(int i=0;i<k;i++)
    {
       if((1<<i)&ans)
         cout<<'1';
       else
         cout<<'0';
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
    //task_b();
    //task_g();
    task_D();
  }

  return 0;
}