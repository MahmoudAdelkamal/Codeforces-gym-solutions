#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll power(ll n)
{
    ll ans=0;
    while(n){
       ans++;
       n/=10;
    }
    return ans;
}
int main()
{
	ll t,n,x,p,diff=0,ans=0,original=0;
	cin>>t;
	while(t--)
        {
           cin>>n>>x;
           original=x;
           p=power(x);
           ans=p;
           while(1)
           {
               diff=pow(10,p)-x;
               if(ans+diff*p<=n)
               {
                   ans+=diff*p+1;
                   x=pow(10,p);
                   p++;
               }
               else
               {
                   x+=(n-ans)/p;
                   if((n-ans)%p!=0)
                     cout<<-1<<endl;
                   else
                     cout<<x-original+1<<endl;
                break;
            }
        }
        ans=0;
        diff=0;
    }
    return 0;
}
