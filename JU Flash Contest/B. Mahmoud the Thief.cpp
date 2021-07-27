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
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    map<int,int>mp;
    int n,m,a[N],b[N];
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        x--;
        b[i] = a[x];
        mp[b[i]%m]++;
    }
    int cur = mp.size(),i = 0,ans = 0;
    while(cur > 1)
    {
        mp[b[i]%m]--;
        if(mp[b[i]%m]==0)
            cur--;
        i++;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}