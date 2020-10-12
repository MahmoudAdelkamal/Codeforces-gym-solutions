#include <bits/stdc++.h>
#define de7k_gamed ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
typedef long double ld;
#define pi acos(-1)
using namespace std;
ll arr[(ll)1e5+5];
int main()
{
    de7k_gamed
    ll t;
    cin>>t;
    while(t--)
    {
        ll sum=0;
        int n;cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        if(n==1)
        {
            cout<<sum<<" "<<arr[0]<<endl;
            continue;
        }
        ll x=__gcd(arr[0],arr[1]);
        for(int i=2;i<n;i++)
            x=__gcd(arr[i],x);
        cout <<sum<<" "<<x << endl;
    }
 	return 0;
}
