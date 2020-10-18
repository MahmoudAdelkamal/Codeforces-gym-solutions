#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=5e4+5;
const ll mod=1000000007;
int main()
{
   ll t;
   cin>>t;
   while(t--)
   {
       ll a[10];
       for(int i=0;i<5;i++)
            cin>>a[i];
       sort(a,a+5);
       cout<<a[4]*a[3]<<endl;
   }
   return 0;
}
