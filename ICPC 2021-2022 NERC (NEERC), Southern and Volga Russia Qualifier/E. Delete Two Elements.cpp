#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <vector>
#include <string>
#include <map>
#define  ll long long
using namespace std;
const int N = 2e5+5;
ll a[N];
int main()
{
    map<long double,ll>mp;
    ll n,ans = 0;
    long double sum = 0;
    cin>>n;
    for(ll i=0;i<n;i++)
        cin>>a[i],mp[a[i]]++,sum+=a[i];
    long double mean = (sum*(n-2))/n;
    for(ll i=0;i<n;i++)
    {
        long double x = (sum-a[i])-mean;
        if(x!=a[i])
            ans+=mp[x];
        else
            ans+=mp[x]-1;
    }
    cout<<ans/2<<endl;
    return 0;
}