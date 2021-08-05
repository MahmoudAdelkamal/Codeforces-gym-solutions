#include<iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long
const int N = 2e5+5;
int main()
{
    int n,m,a[N];
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int idx = 0;
    while(idx<n && a[idx]<m)
        idx++;
    int ans = 2*idx+1;
    if(ans>n)
        cout<<0<<endl;
    else
        cout<<n-ans+1<<endl;
    return 0;
}