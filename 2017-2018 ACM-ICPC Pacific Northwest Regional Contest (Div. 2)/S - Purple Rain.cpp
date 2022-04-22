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
    string s;
    cin >> s;
    int n = s.size(), cnt = 0, mx = -1e9, mn = 1e9;
    int l, r;
    for (int i = 0; i < n; ++i) {
        s[i] == 'B' ? cnt++ : cnt--;
        if (cnt > mx)
            mx = cnt, l = i + 1;
        if (cnt < mn)
            mn = cnt, r = i + 1;
    }
    int diff = abs(mx - mn);
    if (diff > abs(mn) && diff > abs(mx))
        cout << min(l, r) + 1 << ' ' << max(l, r);
    else
        abs(mx) > abs(mn) ? cout << "1 " << l : cout << "1 " << r;
    return 0;
}
