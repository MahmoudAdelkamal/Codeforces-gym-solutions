#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <numeric>
#include <vector>
#include <string>
#include <map>

#define  ll long long
using namespace std;
const int N = 2e5 + 5;

map<int, ll> mp;
ll ans = 0;

ll fp(ll b, int p) {
    if (p == 0)
        return 1;
    ll res = fp(b, p / 2);
    res = res * res;
    if (p % 2 == 1)
        res *= b;
    return res;
}

const int limit[30] = {1000000000, 31622, 1000, 177, 63, 31, 19, 13, 10, 7, 6, 5, 4, 4, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,1};

void calc(int x) {
    for (int pw = 1; pw <= 30; pw++) {
        int l = 1, r = limit[pw-1];

        while (l <= r) {
            int m = (l + r) / 2;
            ll val = fp(m, pw);
            if (val == x) {
                mp[m] += x;
                ans = max(ans, mp[m]);
                break;
            } else if (val < x)
                l = m + 1;
            else
                r = m - 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    int a[N];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1)
        {
            mp[1]++;
            ans = max(ans, mp[1]);
        }
        else
            calc(a[i]);
    }
    cout << ans << '\n';

}