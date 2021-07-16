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
    int n;
    cin >> n;
    string s1, s2, s3, ans = "";
    cin >> s1 >> s2 >> s3;
    for (int i = 0; i < n; ++i) {
        if (s1[i] == s2[i] || s1[i] == s3[i])
            ans += s1[i];
        else if (s2[i] == s3[i])
            ans += s2[i];
        else
            ans += s3[i];
    }
    cout << ans << '\n';
    return 0;
}