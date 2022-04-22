#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const int N = 1e7+5;
ll sum(ll n)
{
    return (n*(n+1))/2;
}
int main()
{
    ll n;
    cin>>n;
    ll total = sum(n-1);
    ll req = (total+1)/2;
    ll cur = 0;
    ll sum = n-1;
    for(int i=1;i<=n;i++)
    {
        cur+=sum;
        sum--;
        if(cur>=req)
            return cout<<i,0;
    }
    return 0;
}
