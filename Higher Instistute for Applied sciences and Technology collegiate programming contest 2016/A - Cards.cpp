#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=5e4+5;
const ll mod=1000000007;
ll solve(ll n)
{
    if(n%2!=0)
        return 1;
    if(solve(n/2)==1)
        return 2;
    else
        return 1;
}
int main()
{
   ll t;
   cin>>t;
   while(t--)
   {
        ll n;
        cin>>n;
        if(solve(n)==1)
            cout<<"First Box"<<endl;
        else
            cout<<"Second Box"<<endl;
   }
   return 0;
}
