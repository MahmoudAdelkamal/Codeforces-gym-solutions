#include<bits/stdc++.h>

using namespace std;
#define fastVictory ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define ll long long
#define endl '\n'
const int N = 2e5 + 5;


int main() {
    fastVictory
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        n -= k;
        ll ans = n / 6;
//        cout<<n<<" "<<ans<<endl;
        if (n % 6)ans++;
        cout << ans << endl;
    }
    return 0;
}