#include <bits/stdc++.h>

#define FIO ios::sync_with_stdio(0); cin.tie(0); ios_base::sync_with_stdio(0);
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const ll mod = 1e9 + 7;
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, 1, -1, 1, -1};


int main() {
    FIO;
    int s;
    cin >> s;
    cout << s << ": \n";
    vector<pair<int, int>> v;
    // 50
    // 25 25
    int mx = (s / 2) + 1;
    for (int x = 2; x <= mx; ++x) {
        int y1 = x - 1, y2 = x;
        // 2 1 // 2 2
        if (s % (x + y1) == 0)
            v.push_back({x, y1});
        else if (s % (x + y1) == x)
            v.push_back({x, y1});
        if (s % (x + y2) == 0)
            v.push_back({x, y2});
        else if (s % (x + y2) == x)
            v.push_back({x, y2});
    }
    sort(v.begin(), v.end());
    for (auto &i: v) {
        cout << i.first << ',' << i.second << '\n';
    }
    /* 13:
     * 3,2
     * 7,6
     */
    return 0;
}
