#include<iostream>
#include<algorithm>
#include<cstring>
#include <complex>
#include<map>
#include<vector>
#include<iomanip>
#include<set>
#include<queue>
using namespace std;
#define ll long long
const int mod = 1000000007;
const int N = 2e5+5;
#define ll long long
typedef complex<ll>point;
#define X real()
#define Y imag()
#define diff(a,b)((b)-(a))
#define cross(a,b)((conj(a)*(b)).imag())
int main()
{
    int n;
    cin>>n;
    pair<int,int>a[n+5];
    for(int i=0;i<n;i++)
        cin>>a[i].first>>a[i].second;
    ll area = 0,boundary = 0; // area = x1*y2 - x2*y1
    for(int i=0;i<n;i++)
    {
        ll x1 = a[i].first,y1 = a[i].second,x2 = a[(i+1)%n].first,y2 = a[(i+1)%n].second;
        area+=x1*y2-x2*y1;
        boundary+=__gcd(abs(x1-x2),abs(y1-y2));
    }
    area = abs(area);
    area/=2;
    cout<<area-boundary/2+1<<endl;

    return 0;
}