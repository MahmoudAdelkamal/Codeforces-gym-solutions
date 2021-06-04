#include <bits/stdc++.h>
#define yala ios::sync_with_stdio(0); cin.tie(0); ios_base::sync_with_stdio(0);
#define RW freopen("input.txt","mirror",stdin), freopen("output.txt","w",stdout);
#define ll long long
#define ld long double
using namespace std;
const int N = 2e5 + 9;
const int MOD = 1e9;
const ll INF = 1e18;
const double pi = 3.1415926536;
const int mod = 1e9 + 7;
typedef complex<ll>point;
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};
int main() {
    yala;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k;
        vector<int> v;
        while (n--) {
            cin >> s;
            string ss = s.substr(33);
            int num = stoi(ss);
            v.push_back(num);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < k; ++i) {
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}