#include<bits/stdc++.h>

using namespace std;
#define fastVictory ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define ll long long
#define endl '\n'
const int N = 1e5 + 5;

int par[N];

int Find(int u) {
    if (u == par[u])
        return u;
    return par[u] = Find(par[u]);
}

int main() {
    fastVictory
    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;
        for (int i = 1; i <= n; i++)
            par[i] = i;
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            par[Find(u)] = Find(v);
        }
        for (int i = 0; i < q; i++) {
            int u, v;
            cin >> u >> v;
            if (Find(u) == Find(v))
                cout << 1;
            else cout << 0;
        }
        cout<<endl;
    }
    return 0;
}