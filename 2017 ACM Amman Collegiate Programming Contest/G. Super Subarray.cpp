#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int N=1e5+5;
ll gcd(ll a,ll b){
	if(b==0)
        return a;
	return
	   gcd(b,a%b);
}
ll Lcm(ll a,ll b){
	return (a*b)/gcd(a,b);
}
int main()
{
    ll t,n,arr[5005],lcm=1;
    cin>>t;
    while(t--)
    {
        ll ans=0;
        cin>>n;
        for(ll i=0;i<n;i++)
            cin>>arr[i];
        for(ll i=0;i<n;i++)
        {
            ll sum=0;
            ll lcm=1;
            for(ll j=i;j<n;j++)
            {
                sum+=arr[j];
                ll lcm2=lcm/gcd(lcm,arr[j]);
                if((ll)20000000000/lcm2<(ll)arr[j])
                    break;
                else
                   lcm=lcm2*arr[j];
                if(sum%lcm==0)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
   return 0;
}
