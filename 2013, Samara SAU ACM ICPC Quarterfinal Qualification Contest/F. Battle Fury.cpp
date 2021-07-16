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
const int N = 2e5+5;
const int mod = 1e9+7;
ll n, p, q,arr[N];
bool bs(int hits)
{
    ll ans = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]-hits*q<=0)
            continue;
        ll need = (arr[i]-hits*q);
        ans+=need/p+((need%p)!=0);
    }
    return(ans<=hits);
}
int main()
{
    ll ans = -1,maxi = 0;
    cin>>n>>p>>q;
    for (int i = 0; i < n; ++i)
        cin >> arr[i],maxi = max(maxi,arr[i]);
    if(p==q)
        return cout<<(maxi/p)+((maxi%p)!=0),0;
    p-=q;
    ll low = 1,high = maxi;
    while (low<=high)
    {
        ll mid = (low+high)/2;
        if(bs(mid))
            ans = mid,high = mid-1;
        else
            low = mid+1;
    }
    cout<<ans<<endl;
    return 0;
}