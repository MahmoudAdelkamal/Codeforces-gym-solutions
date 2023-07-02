#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <vector>
#include <string>

using namespace std;


int main()
{
    long long n,a,b,ans = 1e18;
    cin>>n>>a>>b;
    for(long long i=1;i<=1000;i++)
    {
        for(long long j=1;j<=1000;j++)
        {
            if(i*a+j*b<=n && i<j)
                ans = min(ans,n-(i*a+j*b));
        }
    }
    cout<<ans<<endl;
    return 0;
}