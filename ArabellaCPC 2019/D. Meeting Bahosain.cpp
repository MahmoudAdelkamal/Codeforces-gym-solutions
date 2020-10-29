#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
const int N=1e6+5;
int main()
{
    int n,m,a[N],b[N];
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;i++)
       scanf("%d", &a[i]);
    for(int i=0;i<m;i++)
       scanf("%d", &b[i]);
    if(n==1)
        return printf("Yes\n"),0;
    int gcd1=a[0];
    for(int i=1;i<n;i++)
    {
        gcd1=__gcd(gcd1,a[i]);
    }
    int gcd2=b[0];
    for(int i=1;i<m;i++)
    {
        gcd2=__gcd(gcd2,b[i]);
    }
    if(gcd1%gcd2==0)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
