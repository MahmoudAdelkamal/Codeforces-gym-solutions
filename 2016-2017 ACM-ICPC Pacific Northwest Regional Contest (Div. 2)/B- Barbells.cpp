#include <bits/stdc++.h>
#define salma ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define RW freopen("bad-memes.in", "r", stdin);
typedef long long ll;
typedef long double ld;
#define F first
#define S second
using namespace std;
const int N =  2 * 1e5 + 5 ;
const int M = sqrt(N) + 5;
const int mod = 1e9 + 7;
const double PI = 2 * acos(0);
//int dy[]= {1,-1,0,0,1,1,-1,-1};
//int dx[]= {0,0,1,-1,1,-1,-1,1};
int n, m, b[15], a[15];
set<ll>st;
void solve(int idx, ll w1, ll w2)
{
    if(idx == m)
    {
        if(w1 == w2)
        {
            for(int i = 0; i < n; i++)
                st.insert(a[i] + w1 + w2);
 
        }
            return;
    }
    solve(idx + 1, w1, w2);
    solve(idx + 1, w1 + b[idx], w2);
    solve(idx + 1, w1, w2 + b[idx]);
}
int main()
{
    salma;
    cin >> n >> m;
    for(int i = 0; i < n ; i++)
        cin >> a[i];
    for(int i = 0; i < m ; i++)
        cin >> b[i];
    solve(0, 0, 0);
    for(auto i : st)
        cout << i << endl;
 
    return 0;
}