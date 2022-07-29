#include <bits/stdc++.h>
#define  ll long long
#define endl "\n"
using namespace std;
const int N=1e5+5;
int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        ll n,s,ans = -1e18;
        cin>>n>>s;
        for(int j=0;j<n;j++)
        {
            ll f,t;
            cin>>f>>t;
            if(t<=s)
                ans = max(ans,f);
            else
                ans = max(ans,f-(t-s));
        }
        cout<<"Case "<<"#"<<i<<": "<<ans<<endl;
    }
    return 0;
}