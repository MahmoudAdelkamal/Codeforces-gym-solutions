#include <bits/stdc++.h>
#define de7k_gamed ios_base::sync_with_stdio(false);cin.tie(NULL);//freopen("out.txt","w",stdout);
typedef long long ll;
typedef long long int lli;
typedef long double ld;
#define pi acos(-1)
using namespace std;
 
int main()
{
    de7k_gamed;
    ll t;
    cin>>t;
    while(t--)
    {
        ll x,y;
        cin>>x>>y;
        x=max(x,y);
        cout<<x*x<<'\n';
    }
    return 0;
}