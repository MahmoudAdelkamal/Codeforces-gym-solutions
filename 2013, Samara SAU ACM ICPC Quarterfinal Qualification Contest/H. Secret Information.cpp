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
    string s,t;cin >> s >> t;
    int i=0,j=0,ans=0;
    while (i<n)
    {
        while (i<n && s[i]==t[j])
            i++,j++;
        if(i==n)
            break;
        ans++;
        while (i<n && s[i]!=t[j])
            i++,j++;
    }
    cout << ans << endl;
    return 0;
}