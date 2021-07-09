
#include<iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
const int N = 1e5+5;
const int mod = 1e9+7;
int main()
{
    priority_queue<int,vector<int>,greater<int>>pq;
    int n,k,a[N];
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int idx = 0;
    while(pq.size()<k && idx<n)
        pq.push(a[idx++]);
    ll cur = 0,ans = 0;
    while (pq.size())
    {
        cur+=pq.top();
        pq.pop();
        ans+=cur;
        if(idx<n)
            pq.push(a[idx++]);
    }
    cout<<ans<<endl;
    return 0;
}