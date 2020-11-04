#include <bits/stdc++.h>
#define de7k_gamed ios_base::sync_with_stdio(false);cin.tie(NULL);//freopen("out.txt","w",stdout);
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        ll x=(n/2)+n;
        x/=2;
        ll y=x+n;
        y/=2;
        ll z=n-(n/2)+y;
        bool ok=0;
        ll a=z,b=y,c=x;
        a-=b;
        b+=b;
        b-=c;
        c+=c;
        c-=a;
        a+=a;
        if(a==n&&b==n&&c==n)
            ok=1;
        ok ? cout << z << " " << y << " " << x <<endl : cout <<"Impossible"<<endl;;
    }
    return 0;
}
