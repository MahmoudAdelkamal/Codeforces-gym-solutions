#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=1e5+5;
const ll mod=1000000007;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,maxi=0,mini=1e18;
        cin>>n;
        for(ll i=0;i<n;i++)
        {
            ll x;
            char op;
            cin>>x>>op;
            if(op=='-')
              mini=min(mini,maxi+x+25);
            else
              maxi+=x+25;
        }
        cout<<mini-maxi<<endl;
    }
   return 0;
}
