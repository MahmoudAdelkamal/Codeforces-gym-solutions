#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <iomanip>
#include <map>
#include <queue>
#include <utility>
#include <stack>
#include <unordered_map>
#define ll long long
using namespace std;
const int N = 1e5+5;
const int mod = 1e9+7;
int main() {
    map<ll, ll> mp;
    ll n, s, sum = 0, ans = 0;
    cin >> n >> s;
    ll arr[n + 5];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == s)
            ans++;
        if (mp.count(sum - s))
            ans += mp[sum - s];
        mp[sum]++;
    }
    cout << ans << "\n";
    return 0;
}