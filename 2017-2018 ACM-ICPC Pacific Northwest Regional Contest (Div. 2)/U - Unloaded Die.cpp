#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
int main()
{
    double a[6];
    for(int i=0;i<6;i++)
        cin>>a[i];
    double sum = 0;
    for(int i=0;i<6;i++)
        sum+=(i+1)*a[i]*1.0;
    double ans = 1e8;
    double diff = 3.5 - sum;
    for(int i=0;i<6;i++)
        ans = min(ans,abs(diff/a[i]));
    cout<<fixed<<setprecision(3)<<ans<<endl;
    return 0;
}
