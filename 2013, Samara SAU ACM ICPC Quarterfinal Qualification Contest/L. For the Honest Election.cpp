#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <iomanip>
#include <map>
#include <queue>
#include <utility>
#include <stack>
#include <unordered_map>
#define ll long long
using namespace std;
const int N = 1e5+5;
const int mod = 1e9+7;
ll n;
map<ll,ll>mp;
ll solve(ll x)
{
    if(mp[x])
        return mp[x];
    ll ans = x/2+1;
    for(ll i=2;1LL*i*i<=x;i++)
    {
        if((x%i)!=0)
            continue;
        ll tmp = x/i;
        ans = min(ans,solve(i)*(tmp/2+1));
        ans = min(ans,solve(tmp)*(i/2+1));
    }
    return mp[x] = ans;
}
int main()
{
    cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}