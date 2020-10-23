#define _USE_MATH_DEFINES
#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,s;
        cin>>n>>s;
        if((n%2==0 && s%2==1) || (n*9<s))
        {
            cout<<-1<<'\n';
            continue;
        }
        int a[n+5];
        for(int l=1,r=n,x=9;l<=(n/2);l++,r--)
        {
            while(2*x>s && x>0)
                x--;
            a[l]=x;
            a[r]=x;
            s-=2*x;
        }
        if(n%2==1)
            a[(n/2)+1]=s;
        if(a[1]==0 && n>1)
        {
            cout<<-1<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++)
            cout<<a[i];
        cout<<'\n';
}
  return 0;
}
