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
        ll n,ans=0;
        cin>>n;
        ll a[n]={};
        for (ll j=0;j<3;j++)
        {
            for (ll i=0;i<n*3;i++)
            {
                char c;
                cin>>c;
                if (c=='*')
                    a[i/3]+=4;
                ans=max(ans,a[i/3]);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}