#include<iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
#define ll long long
const int mod = 1000000007;
const int N = 1e5+5;
#define ll long long
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll n,a[N],b[N],cum[N]={},mini = 1e18,ans = 0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i]>>b[i];
    sort(a,a+n);
    sort(b,b+n);
    for(int i=0;i<n;i++)
        cum[i] = a[i];
    for(int i=1;i<n;i++)
        cum[i]+=cum[i-1];
    for(int i=0;i<n;i++)
    {
        int idx = upper_bound(a,a+n,b[i])-a;
        ll tmp = b[i]*(idx-i);
        if(idx<n)
        {
            if(idx)
                tmp+=(cum[n-1]-cum[idx-1]);
            else
                tmp+=cum[n-1];
        }
        if(tmp>ans)
            ans = tmp,mini = b[i];
    }
    cout<<mini<<" "<<ans<<endl;
    return 0;
}