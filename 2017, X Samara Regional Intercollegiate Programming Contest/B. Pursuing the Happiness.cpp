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

void task_a() {

}

void task_b() {

}


void task_g() {
  string s;
  cin >> s;
  string fake = "happiness";
  size_t found = s.find(fake);
  vector<int> ans;
  while (found != string::npos) {
    ans.eb(found);
    found = s.find(fake, found + 1);
  }
  if (ans.size() > 2) {
    cout << "NO\n";
    return;
  }
  if (ans.empty()) {
    for (int i = 0; i + 1 < s.size(); i++) {
      if (s[i] == s[i + 1]) {
        cout << "YES\n";
        cout << i + 1 << " " << i + 2 << "\n";
        return;
      }
    }
    cout << "YES\n";
    cout << 1 << " " << 2 << endl;
    return;
  }
  vector<pair<int, int>> res;
  if (ans.size() == 1) {
    res.eb(ans[0], ans[0] + 1);
  } else {
    res.eb(ans[0], ans[1] + 1);
  }
  cout << "YES\n";
  cout << res.back().first + 1 << " " << res.back().second + 1 << endl;
}


void task_d() {

}

void task_m() {
  int n;
  cin >> n;
  vector<pair<ll, int>> v;
  queue<int> q;
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    ll a;
    cin >> a;
    res += a;
    if (a == 0) {
      q.push(i);
    } else {
      v.eb(a, i);
    }
  }
  if (res >= n) {
    cout << "NO\n";
    return;
  }
  vector<pair<int, int>> ans;
  for (int i = v.size() - 1; i >= 0; --i) {
    while (!q.empty() and v[i].first > 0) {
      v[i].first--;
      ans.pb({v[i].second, q.front()});
      q.pop();
    }
    if (v[i].first > 0) {
      cout << "NO\n";
      return;
    }
    q.push(v[i].second);
  }
  cout << "YES\n";
  for (auto i : ans) {
    cout << i.first + 1 << " " << i.second + 1 << endl;
  }

}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  // cin >> t;
  for (int i = 1; i <= t; ++i) {
    //task_a();
    // task_b();
    task_g();
    // task_d();
    //task_m();
  }

  return 0;
}