#include <bits/stdc++.h>

typedef long long ll;
#define endl '\n'
#define pq priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
#define graph1 vector<vector<pair<ll,ll>>>
#define graph vector<vector<ll>>
#define pq1 priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll,ll>>>, greater<pair<ll, pair<ll, ll>>>>
#define loop(i, a, b) for (ll i = a; i < b; i++)
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        long double b1, p1, b2, p2;
        cin >> b1 >> p1 >> b2 >> p2;
        long double tmp1 = p1 * log10(b1);
        long double tmp2 = p2 * log10(b2);
        if (b1 == 0 || b2 == 0) {
            if (b1 == 0 && b2 == 0)
                cout << "Lazy" << endl;
            else if (b1 == 0 && b2 != 0)
                cout << "Congrats" << endl;
            else if (b1 != 0 && b2 == 0)
                cout << "HaHa" << endl;
        } else {
            if (fabs(tmp1 - tmp2) <= 1e-6) {
                cout << "Lazy" << endl;
            } else if (tmp1 > tmp2)
                cout << "HaHa" << endl;
            else if (tmp1 < tmp2)
                cout << "Congrats" << endl;
        }
    }
}