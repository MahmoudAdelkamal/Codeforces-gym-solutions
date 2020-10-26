#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
const int N=1e6+5;
bool isPrime[N];
vector<int>primes;
void sieve()
{
    memset(isPrime,1,sizeof(isPrime));
    isPrime[0]=0,isPrime[1]=0;
    for(ll i=2;i<N;i++)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
            for(ll j=i*i;j<N;j+=i)
                isPrime[j]=0;
        }
    }
}
int main()
{
    sieve();
    ll x,ans=0;
    cin>>x;
    while(x>=4)
    {
        ll diff=0;
        for(auto i:primes)
        {
            if(i>x)
                break;
            if(isPrime[i] && isPrime[x-i])
            {
                diff = (x-i)-i;
                break;
            }
        }
        x=diff;
        ans++;
    }
    cout<<ans;
    return 0;
}
