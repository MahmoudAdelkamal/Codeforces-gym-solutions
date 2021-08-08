#include <bits/stdc++.h>
using namespace std;
const int N=2e7+5;
#define ll long long
bool vis[N];
int main()
{
    ll p,n; scanf("%lld %lld",&p,&n);
    ll cur=0,ans=1,idx=1;
    vis[0]=1;
    n=min(n,2*p);
    while(n>0)
    {
        cur=(cur+idx)%p;
        if(!vis[cur]){
            ans++;
            vis[cur]=1;
        }
        n--;
        idx++;
    }
   printf("%lld",ans);
}