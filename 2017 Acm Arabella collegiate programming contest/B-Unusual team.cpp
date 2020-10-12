#include <bits/stdc++.h>
#define de7k_gamed ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
typedef long double ld;
using namespace std;
int main()
{
    de7k_gamed
    ll t;
    cin>>t;
    while(t--)
    {
       ll a,b;
       cin>>a>>b;
       if(a<b)
        cout<<"WeWillEatYou\n";
       else
        cout<<"FunkyMonkeys\n";
    }
    return 0;
}
