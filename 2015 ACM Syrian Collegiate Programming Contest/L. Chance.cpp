#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=1e5+5;
const ll mod=1000000007;
int ans[N];
bool isPrime(int x)
{
    int ans=0;
    for(int i=1;i<=x;i++)
    {
        if(x%i==0)
         ans++;
    }
    return(ans==2);
}
int main()
{
    for(ll i=1;i<=N;i++)
    {
        ans[i]+=ans[i-1];
        int x=i,cnt=0;
        while(x)
        {
            cnt+=x%2;
            x/=2;
        }
        if(isPrime(cnt))
            ans[i]++;
    }
    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        cout<<ans[r]-ans[l-1]<<endl;
    }
   return 0;
}
