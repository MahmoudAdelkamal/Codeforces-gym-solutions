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
#define eps 1e-9
#define zero(x) (abs (x) < eps)
#define equal(a, b) (zero ((a) - (b)))
#define pi pair<ll,ll>
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll N = 300001, NN = 1e4 * 8 + 2, mod = 1e9 + 7;
int n,m;
map<string,vector<string>>adj1,adj2;
string a,b,tmp;
bool dfs1(string node)
{
    if(node==b)
        return 1;
    vector<string>v = adj1[node];
    for(auto i:v)
    {
        if(dfs1(i))
            return 1;
    }
    return 0;
}
bool dfs2(string node)
{
    if(node==a)
        return 1;

    vector<string>v = adj1[node];
    for(auto i:v)
    {
        if(dfs2(i))
            return 1;
    }
    return 0;
}
void d()
{
    cin>>n>>m;
    for (int i = 0; i < n; ++i) {
        cin>>a>>tmp>>tmp>>tmp>>b;
        adj1[a].push_back(b);
    }
    while (m--)
    {
        cin>>a>>tmp>>tmp>>tmp>>b;
        if(dfs1(a))
            cout<<"Fact"<<endl;
        else if(dfs2(b))
            cout<<"Alternative Fact"<<endl;
        else
            cout<<"Pants on Fire"<<endl;
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
        d();
    }
    return 0;
}