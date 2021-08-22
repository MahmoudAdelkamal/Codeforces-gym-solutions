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
#define f first
#define s second
#define eb emplace_back
#define endl '\n'
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void err() { cerr << endl; }

template<typename Head, typename ...Tail>
void err(Head H, Tail ... T) { cerr << " " << to_string(H), err(T...); }

const ll N = 1e5 + 5, NN = 1e4 * 8 + 2, mod = 998244353;
map<ll, ll> p;
vector<int> ok;

void j() {
    for (ll i = 2; i * i <= N; i++) {
        if (p[i] == 0) {
            for (ll j = i * i; j < N; j += i)p[j] = 1;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (p[i] == 0)ok.eb(i);
    }
    ll maxx = 0;
    for (int i = 0; i < ok.size() - 1; ++i) {
        maxx = max(maxx, (ll) ok[i + 1] - ok[i]);
    }
    cout << maxx << endl;

}

pair<int,int>a[N];
int n,ans[N];
void f() {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin>>a[i].first;
        a[i].second = n+1;
    }
    a[n+1] = {INT_MAX,n+1};
    for(int i=n;i>0;i--)
    {
        if(a[i].first < a[i+1].first)
            ans[i] = 0,a[i].second = i+1;
        else
        {
            int tmp = a[i+1].second;
            while(a[tmp].first<=a[i].first && tmp<=n)
                tmp = a[tmp].second;
            a[i].second = tmp;
            ans[i] = min(tmp-1-i,a[i].first);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; ++i) {
         f();
       // j();
    }
    return 0;
}