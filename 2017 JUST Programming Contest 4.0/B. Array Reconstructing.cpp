#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int N=2e5+5;
const int mod=1e9+7;
int a[N];
ll sum(ll x)
{
    return (x*(x+1))/2;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n,ans = 0;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=29;i>=0;i--)
        {
            ll cnt = 0;
            for(int j=0;j<n;j++)
            {
                if(a[j]&(1LL<<i))
                    cnt++;
                else
                {
                    ans+=1LL*sum(cnt)*(1LL<<i);
                    cnt = 0;
                }
            }
            ans+=1LL*sum(cnt)*(1LL<<i);
        }
        //for(int i=0;i<n;i++)
          //  ans+=a[i];
        cout<<ans<<endl;
    }
    return 0;
}