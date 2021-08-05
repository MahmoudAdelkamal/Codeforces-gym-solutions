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
const long long N = 1e5 + 5, NN = 1e7 + 5, mod = 1e9 + 7;

void task_e() {
  string pass, enter;
  cin >> pass >> enter;

  if (pass == enter) {
    cout << "yes\n";
    return;
  }
  if (pass.size() < 8) {
    cout << "no\n";
    return;
  }
  for (int i = 0; i < pass.size(); i++) {
    int k = 0, ok = 0;
    for (int j = 0; j < pass.size(); j++) {
      if (pass[j] == enter[k])++k;
      else if (i == j) {
        ++k;
        ok = 1;
        continue;
      }
    }

    if (k + (!ok && (pass.size() > enter.size())) == pass.size()) {
      cout << "yes\n";
      return;
    }
  }
  cout << "no\n";


}

vector<char> op;
vector<ll> v;
int n;

ll solve(int indx, ll sum) {
  if (indx == n) {
    if (sum == 0)return 0;
    return 1e18;
  }
  ll ret = 1e18;
  ret = min(ret, solve(indx + 1, sum + v[indx]) + (op[indx - 1] == '+' ? 0 : 1));
  ret = min(ret, solve(indx + 1, sum - v[indx]) + (op[indx - 1] == '+' ? 1 : 0));
  return ret;
}

void l() {
  cin >> n;
  cin.ignore();
  string s;
  getline(cin, s);
  ll nm = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == ' ') {
      if (nm != 0) {
        v.pb(nm);
        nm = 0;
      }
      continue;
    }
    if (s[i] == '+' or s[i] == '-')op.pb(s[i]);
    else {
      nm *= 10;
      nm += s[i] - '0';
    }
  }
  if (nm != 0)
    v.pb(nm);
  ll res = solve(1, v[0]);
  if (res == 1e18)cout << -1 << endl;
  else cout << res << endl;
}

ll a[6] = {1, 5, 10, 20, 50};

void h() {
  int n;
  cin >> n;
  ll pay[70] = {};
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    ll sum = 0;
    for (int j = 0; j < 5; j++) {
      ll x;
      cin >> x;
      pay[a[j]] += x;
      sum += x * a[j];
    }
    ll diff = sum - k;
    for (int j = 4; j >= 0; j--) {
      while (pay[a[j]] && diff >= a[j])pay[a[j]]--, diff -= a[j];
    }
    if (diff) {
      cout << "no";
      return;
    }
  }
  cout << "yes";
}

void e() {
  string a, b;
  cin >> a >> b;
  int n = a.length();
  int m = b.length();
  if (a == b) {
    cout << "yes\n";
    return;
  }
  if (n < 8) {
    cout << "no\n";
    return;
  }
  if (m - n >= 1) {
    cout << "no\n";
    return;
  }
  if (n - m >= 2) {
    cout << "no\n";
    return;
  }
  if (n == m) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i])cnt++;
    }
    if (cnt >= 2) {
      cout << "no\n";
      return;
    }
    cout << "yes\n";
  } else {
    int cnt = 0;
    bool ok = false;
    for (int i = 0; i < m; ++i) {
      if (a[i] != b[i - ok]) {
        cnt++;
        ok = 1;
      }
    }
    if (cnt >= 2) {
      cout << "no\n";
      return;
    }
    cout << "yes\n";
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
    //task_e();
    h();
    //l();
    //e();
  }
  return 0;
}