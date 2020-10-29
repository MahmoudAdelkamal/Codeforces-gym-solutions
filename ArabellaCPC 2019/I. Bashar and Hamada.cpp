#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
const int N=1e6+5;
ll sum1[N],sum2[N],a[N];
int main()
{
    ll n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
       sum1[i]=sum1[i-1]+a[n-i+1];
       sum2[i]=sum2[i-1]+a[i];
    }
    for(int i=2;i<=n;i++)
    {
        ans+=abs(sum1[i/2]-sum2[i/2]);
        cout<<ans<<" ";
    }
    return 0;
}
