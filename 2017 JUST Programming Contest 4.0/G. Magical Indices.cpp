#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int N=1e6+5;
const int mod=1e9+7;
int a[N],pref[N],suff[N];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,ans = 0;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        int maxi = 0;
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi,a[i]);
            pref[i] = maxi;
        }
        int mini = INT_MAX;
        for(int i=n-1;i>=0;i--)
        {
            mini = min(mini,a[i]);
            suff[i] = mini;
        }
        for(int i=1;i<n-1;i++)
        {
            if(a[i]>=pref[i] && a[i]<=suff[i])
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}