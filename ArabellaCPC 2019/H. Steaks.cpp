#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
const int N=55;
int main()
{
    ll n,k;
    cin>>n>>k;
    if(n<=2*k)
        cout<<10<<endl;
    else
    {
        ll ans=(n)/(k);
        if((n)%(k)!=0)
            ans++;
        ans*=5;
        cout<<ans<<endl;
    }
    return 0;
}
