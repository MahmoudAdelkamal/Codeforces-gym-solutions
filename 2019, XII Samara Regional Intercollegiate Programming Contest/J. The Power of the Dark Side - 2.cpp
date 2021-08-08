#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int n,a[N],b[N],c[N];
vector<ll>v;
int main()
{
   scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d",a+i,b+i,c+i);
        if (a[i]>b[i])
            swap(a[i],b[i]);
        if (a[i]>c[i])
            swap(a[i],c[i]);
        if (b[i]>c[i])
            swap(b[i],c[i]);
        v.push_back(a[i]+b[i]+2);
    }
    sort(v.begin(),v.end());
    for (int i=0;i<n;i++){
        int ans=upper_bound
                (v.begin(),v.end(),
                        1LL*a[i]+b[i]+c[i])-v.begin();
        if(c[i]>=2)
            ans--;
        printf("%d ",ans);
    }
    return 0;
}