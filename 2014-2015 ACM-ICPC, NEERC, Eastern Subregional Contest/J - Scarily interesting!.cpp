#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=1e3+5;
const ll mod=1000000007;
int main()
{
    pair<ll,ll>p1[N],p2[N];
    int n,ans1=0,ans2=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        p1[i]={x,i+1};
        ans1+=x;
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        p2[i]={x,i+1};
        ans2+=x;
    }
    sort(p1,p1+n);
    sort(p2,p2+n);
    if(ans2>ans1)
    {
        for(int i=0,j=n-1;i<n && j>=0;i++,j--)
            cout<<p1[j].second<<" "<<p2[i].second<<endl;
    }
    else
    {
        for(int i=0,j=n-1;i<n && j>=0;i++,j--)
            cout<<p1[i].second<<" "<<p2[j].second<<endl;
    }
    return 0;
}
