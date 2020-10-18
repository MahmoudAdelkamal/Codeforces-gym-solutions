#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=2e5+5;
const ll mod=1000000007;
ll a[N],b[N];
int main()
{
   ll t;
   cin>>t;
   while(t--)
   {
        memset(b,0,sizeof(b));
        int n,m;
        ll ans[N];
        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            b[x-1]+=y;
        }
        ll res=0;
        for(int i=0;i<n;i++)
        {
            if(b[i]>a[i])
            {
                ans[i]=a[i];
                if(i==n-1)
                   res+=b[i]-a[i];
				else
				   b[i+1]+=b[i]-a[i];
            }
            else
                ans[i]=b[i];
        }
        cout<<res<<'\n';
        for (int i=0;i<n;i++)
        {
            if(i==n-1)
                cout<<ans[i]<<endl;
            else
                cout<<ans[i]<<" ";
        }
   }
   return 0;
}
