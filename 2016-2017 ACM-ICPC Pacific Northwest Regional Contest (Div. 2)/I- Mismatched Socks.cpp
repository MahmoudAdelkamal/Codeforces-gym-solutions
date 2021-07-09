#include <bits/stdc++.h>
 
#define sr3 ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
const int N = 2e5 + 5, inf = 2e9, mod = 1e9 + 7;
 
 
int main() {
    sr3
    int n; cin>>n;
    ll mx=0,sum=0;
    for(ll i=0,x; i<n&&cin>>x; i++)
        sum+=x,mx=max(mx,x);
    if(sum>=2*mx)cout<<sum/2<<endl;
    else cout<<sum-mx<<endl;
    return 0;
}