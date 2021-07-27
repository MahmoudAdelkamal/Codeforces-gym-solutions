#include<iostream>
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <cmath>
using namespace std;
#define ll long long
const int N = 2e5+5;
ll n,m,arr[N],pref[N];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        pref[i] = pref[i-1]+arr[i];
    }
    if(n==1)
        return cout<<m,0;
    for(int i=1;i<=n;i++)
    {
        ll left = pref[i-1];
        ll right = pref[n] - pref[i];
        ll ans = max(left+right+m,max(left,right));
        cout<<ans<<" ";
    }
    return 0;
}