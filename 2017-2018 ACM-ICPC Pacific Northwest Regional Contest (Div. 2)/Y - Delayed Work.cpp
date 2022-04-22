#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const int N = 1e7+5;
int main()
{
    ld ans = 1e18;
    ll k,p,x;
    cin>>k>>p>>x;
    for(int i=1;i<N;i++)
    {
        ld tmp = (ld)k/i*p + x*i;
        ans = min(ans,tmp);
    }
    cout<<fixed<<setprecision(3)<<ans<<endl;
    return 0;
}
