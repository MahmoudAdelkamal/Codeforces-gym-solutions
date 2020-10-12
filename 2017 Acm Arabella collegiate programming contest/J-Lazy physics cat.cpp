#include <bits/stdc++.h>
#define de7k_gamed ios_base::sync_with_stdio(false);cin.tie(NULL);//freopen("out.txt","w",stdout);
typedef long long ll;
typedef long double ld;
#define pi acos(-1)
using namespace std;
int main()
{
    de7k_gamed
    ll t;
    cin>>t;
    while(t--)
    {
        ld l,a;
        cin>>l>>a;
        ld sector_area = (a/360)*(pi)*l*l;
        ld triangle_area = (0.5)*l*l*sin((a*pi)/180);
        cout<<fixed<<setprecision(6)<<sector_area-triangle_area<<endl;
    }
 	return 0;
}
