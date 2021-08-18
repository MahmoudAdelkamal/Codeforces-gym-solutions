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
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T> using ordered_multi_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll N = 1e5 + 5, NN = 1e4 * 8 + 2, mod = 1e9 + 7;


void a()
{

}
void k()
{
    int n,d,k;
    cin>>n>>d>>k;
    pair<int,string>p[N];
    for(int i=0;i<n;i++)
        cin>>p[i].second>>p[i].first;
    sort(p,p+n);
    ll sum = 0,cnt = 0;
    for(int i=n-1;i>=0;i--)
    {
        sum+=p[i].first;
        cnt++;
        if(cnt>k)
        {
            cout<<"impossible"<<endl;
            return;
        }
        if(sum>=d)
        {
            cout<<cnt<<"\n";
            for(int j=n-1;j>=i;j--)
                cout<<p[j].second<<", "<<"YOU ARE FIRED!"<<endl;
            return;
        }
    }
    cout<<"impossible"<<endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    for (int i = 1; i <= t; ++i) {
        k();
    }
    return 0;
}