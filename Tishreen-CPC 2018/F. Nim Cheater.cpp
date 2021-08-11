#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int main()
{
    ll t,m;
    cin>>t;
    while(t--){
        cin>>m;
        ll arr[m+5];
        ll x=0;
        for(ll i=0;i<m;i++)
            cin>>arr[i],x^=arr[i];
        if(x!=0)
            cout<<0<<endl;
        else
            cout<<1<<endl;
    }
  return 0;
}
