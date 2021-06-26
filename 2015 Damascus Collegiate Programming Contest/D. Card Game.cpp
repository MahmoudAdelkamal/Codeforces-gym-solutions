#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#define ll long long
using namespace std;
const int N = 1e6+5;
const int mod = 1e9+7;
ll n,k,ans,arr[N];
bool valid(ll mid)
{
    ans = 0;
    ll sum = 0,maxi = 0,num = 1;
    for(int i=0;i<n;i++)
    {
        sum++;
        maxi = max(maxi,arr[i]);
        if(maxi*sum>mid)
        {
            if(sum==1 || num==k)
                return false;
            sum = 1;
            maxi = arr[i];
            num++;
        }
        ans = max(ans,maxi*sum);
    }
    return true;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        ll low = 1,high = 1e18;
        while(low<high)
        {
            ll mid = (low+high)/2;
            if(valid(mid))
                high = mid;
            else
                low = mid+1;
        }
        valid(high);
        cout<<ans<<"\n";
    }
    return 0;
}