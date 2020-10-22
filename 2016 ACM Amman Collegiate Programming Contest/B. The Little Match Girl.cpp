#include <bits/stdc++.h>
#define de7k_gamed ios_base::sync_with_stdio(false);cin.tie(NULL);//freopen("out.txt","w",stdout);
typedef long long ll;
typedef long double ld;
using namespace std;
int to_sticks[10],to_digits[10];
int n,k,cnt,ans;
int main()
{
    de7k_gamed;
	to_digits[2] = 1;
	to_digits[3] = 7;
	to_digits[4] = 4;
	to_digits[5] = 5;
	to_digits[6] = 9;
	to_digits[7] = 8;

	to_sticks[0] = 6;
	to_sticks[1] = 2;
	to_sticks[2] = 5;
	to_sticks[3] = 5;
	to_sticks[4] = 4;
	to_sticks[5] = 5;
	to_sticks[6] = 6;
	to_sticks[7] = 3;
	to_sticks[8] = 7;
	to_sticks[9] = 6;
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,cntr=0;
        string s;
        cin>>n>>s;
        for(ll i=0;i<n;i++)
        {
            cntr+=(to_sticks[s[i]-'0']-to_sticks[1]);
            s[i]='1';
        }
        for(ll i=0;i<n && cntr>0;i++)
        {
            if (cntr>=to_sticks[9]-to_sticks[1])
                cntr-=(to_sticks[9]-to_sticks[1]),s[i]='9';
            else if (cntr>=to_sticks[7]-to_sticks[1] && i!=n-1)
                cntr-=(to_sticks[7]-to_sticks[1]),s[i]='7';
            else
                s[i]='0'+to_digits[cntr+to_sticks[1]],cntr=0;
        }
        for (ll i=n-1;i>=0 && cntr>0;i--)
            s[i]='8',cntr-=(to_sticks[8]-to_sticks[9]);
        cout<<s<<'\n';
    }
     return 0;
}
