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
    int k = 0;
    for (int j=0;j<pass.size();j++){
      if (i == j)continue;
      if (pass[j] == enter[k])++k;
      cout << k <<" ";

    }
      return;
  }

}
int n,q,a[N];

void d()
{
    set<pair<int,int>>st;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
       cin>>a[i];
       st.insert({a[i],i});
    }
    while(q--)
    {
        string s;
        int x;
        cin>>s>>x;
        if(s=="in")
        {
            auto it = st.lower_bound({x,0});
            if(it==st.end())
              cout<<-1<<endl;
            else
            {
                cout<<(*it).second<<endl;
                st.erase(it);
            }

        }
        else
          st.insert({a[x],x});
    }
}
void f() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> v(n);
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    mp[v[i]]++;
  }
  for (int i = 0; i < q; ++i) {
    int a, b;
    cin >> a >> b;
    mp[v[a - 1]]--;
    if (mp[v[a - 1]] <= 0) {
      mp.erase(v[a - 1]);
    }
    v[a - 1] = b;
    mp[v[a - 1]]++;
    cout << m - mp.size() << endl;
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
    d();
  }
  return 0;
}