#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int N=1e5+5;
int main()
{
    ll t,n,m;
    cin>>t;
    while(t--)
    {
        ll ans;
        cin>>n>>m;
        if(n>m)
            swap(n,m);
        if(n%2!=0)
            ans=1;
        else
            ans=m%2;
        if(ans)
            cout<<"hasan"<<endl;
        else
            cout<<"abdullah"<<endl;
    }
   return 0;
}
