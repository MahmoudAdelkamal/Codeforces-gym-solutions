#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <iomanip>
#include <set>
using namespace std;
#define ll long long
const int mod = 1000000007;
const int N = 2e5+5;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int k,n;
    cin>>k>>n;
    pair<int,int>p[N];
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        p[i].first = x;
        p[i].second = i;
    }
    map<int,int>mp;
    sort(p,p+n);
    for(int i=0;i<n;i++)
    {
        if(k<=0)
            break;
        int ans = min(k,p[i].first);
        mp[p[i].second] = ans;
        k-=ans;
    }
    for(int i=0;i<n;i++)
        cout<<mp[i]<<" ";
    return 0;
}