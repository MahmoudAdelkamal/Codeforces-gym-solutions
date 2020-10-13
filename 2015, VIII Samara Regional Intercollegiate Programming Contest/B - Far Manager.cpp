#include <bits/stdc++.h>
#define de7k_gamed ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
typedef long double ld;
using namespace std;
int main()
{
    ll p,n,x;
    cin>>p>>n>>x;
    ll ans = x/p+x%p;
    ll tmp = x/p+2+p-1-x%p ;
    if(n/p!=0)
        ans = min(ans,tmp);
    cout<<min(ans,n/p+1+n/p-x/p+abs(n%p-x%p))<<endl;
 	return 0;
}
