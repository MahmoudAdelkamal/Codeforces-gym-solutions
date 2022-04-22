#include <bits/stdc++.h>

#define FIO ios::sync_with_stdio(0); cin.tie(0); ios_base::sync_with_stdio(0);
#define ll long long
using namespace std;
const int N = 1e5 + 5;
const ll mod = 1e9 + 7;
int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, 1, -1, 1, -1};

bool check(int x) {
    while (x) {
        if (x % 10 == 0)
            return false;
        x /= 10;
    }
    return true;
}

int main() {
    FIO;
    int n, ans;
    cin >> n;
    while (n++) {
        if (check(n)) {
            ans = n;
            break;
        }
    }
    cout << ans << '\n';
    return 0;
}
