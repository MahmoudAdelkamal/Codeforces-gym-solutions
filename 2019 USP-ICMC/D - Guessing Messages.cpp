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

const ll N = 2501, NN = 1e4 * 8 + 2, mod = 998244353;

void d()
{
    string s,t;
    cin>>s>>t;
    int idx = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==t[idx])
            idx++;
        if(idx==t.size())
            break;
    }
    if(idx==t.size())
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        d();
    }
    return 0;
}