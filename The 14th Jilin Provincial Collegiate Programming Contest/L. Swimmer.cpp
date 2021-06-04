#include <bits/stdc++.h>
 
#define IO  ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define file freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define endl '\n'
#define f first
#define s second
#define ll long long
#define ld long double
#define mod 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
 
using namespace std;
const int M = 2e3 + 5;
 
 
int main() {
    IO
    int n,m,q;
    ll p,k,rem;
    ll Distance;
    cin>>n>>m>>q;
    vector<ll>v(n);
    for(auto &i:v) cin>>i;
    while(q--){
        cin>>p>>k;
        k--;
        Distance=v[k]*p;
        rem=Distance/m;
        Distance%=m;
        if(rem%2){
            cout<<m-Distance<<endl;
        }
        else cout<<Distance<<endl;
    }
    return 0;
}