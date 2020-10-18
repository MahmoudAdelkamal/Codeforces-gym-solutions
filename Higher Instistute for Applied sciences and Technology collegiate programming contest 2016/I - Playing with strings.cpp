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
        ll ans=0;
        string s1,s2;
        cin>>s1>>s2;
        map<char,ll>mp1,mp2;
		for(ll i=0;i<s1.size();i++)
			mp1[s1[i]]++;
		for(ll i=0;i<s2.size();i++)
			mp2[s2[i]]++;
		for(char i='a';i<='z';i++)
			ans+=abs(mp1[i]-mp2[i]);
		cout<<ans<<endl;
   }
   return 0;
}
