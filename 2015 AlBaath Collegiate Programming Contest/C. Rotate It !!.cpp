#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int N=3e5+5;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll ans=-1e18;
        deque<ll>dq;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            ll x;
            cin>>x;
            dq.push_back(x);
        }
        for(int i=0;i<n;i++)
        {
            ll sum=0;
            for(int j=0;j<n;j+=2)
                sum+=dq[j];
            ans=max(ans,sum);
            dq.push_back(dq.front());
            dq.pop_front();
        }
        cout<<ans<<endl;
    }
    return 0;
}
