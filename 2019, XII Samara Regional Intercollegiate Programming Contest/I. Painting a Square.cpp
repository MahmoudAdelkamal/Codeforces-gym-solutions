#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int main()
{
    ll a,b,ans=0;
    cin>>a>>b;
    if(a==b)
        return cout<<0,0;
    while(a>0)
    {
        if(a<b)
          ans+=a;
        else
          ans+=2*a-b;
        a-=b;
    }
    ans-=b;
    cout<<ans<<endl;
}