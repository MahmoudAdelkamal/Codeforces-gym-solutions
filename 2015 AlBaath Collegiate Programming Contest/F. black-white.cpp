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
        ll x,y,z;
        cin>>x>>y>>z;
        if (abs(y-z-1)%2==0)
            cout<<"Mikael\n";
        else
            cout<<"Steven\n";
    }
    return 0;
}
