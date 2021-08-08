#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define ll long long
ll arr[N],a[N],ans[N];
int main()
{
    ll n,l=0,r=1;
    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    while(l<n)
    {
        while(r<=n)
        {
            if((a[r]>0 && arr[a[r]]>0))
                break;
            r++;
            if(a[r-1]<0)
                arr[-a[r-1]]++;
        }
        ans[l]=r-l-1;
        l++;
        if(a[l]<0)
            arr[-a[l]]--;
    }
    for(ll i=0;i<n;i++)
        cout<<ans[i]<<" ";
    return 0;
}