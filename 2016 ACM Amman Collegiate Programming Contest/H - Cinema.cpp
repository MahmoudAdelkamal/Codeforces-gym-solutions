#include <bits/stdc++.h>
#include <unordered_map>
#define ReadFile freopen("input.txt","r",stdin); // matnsash deh ';'
#define ReadFiles freopen("string.in","r",stdin);
#define WriteFile freopen("output.txt","w",stdout); // matnsash deh ';'
#define MEGA_MIND ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define M_PI 3.14159265358979323846
#define mod 1000000007
#define endl "\n"
#define point complex<ld>
using namespace std;
using ll = long long;
using lli = long long int;
using ld = long double;
const int N = 1e5 + 5, inf = 1e18;
int main()
{

	MEGA_MIND
        int t;
        cin>>t;
	while(t--)
	{
	    string s;
	    bool ok = 0;
	    int n,k,cnt=0;
            cin>>n>>k>>s;
	    for(int i=0;i<n;i++)
	    {
		if(cnt>=k+1)
		{
       		    ok=1;
		    break;
		}
		if(s[i]=='0')
		    cnt++;
		else
		    cnt = 0;
	     }
             if(cnt>=k+1)
                 ok=1;
	     ok ?cout<<"yes"<<endl:cout<<"no"<<endl;
	 }
	return 0;

}
