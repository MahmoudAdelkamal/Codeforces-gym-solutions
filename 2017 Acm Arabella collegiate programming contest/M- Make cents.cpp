#include <bits/stdc++.h>
#define de7k_gamed ios_base::sync_with_stdio(false);cin.tie(NULL);//freopen("out.txt","w",stdout);
typedef long long ll;
typedef long double ld;
using namespace std;
int main()
{
    de7k_gamed
    unordered_map<string,double>mp;
    ll t;
    cin>>t;
    while(t--)
    {
        int c,n;
        cin>>c>>n;
        for(int i=0;i<c;i++)
        {
            string s;
            double x;
            cin>>s>>x;
            mp[s]=x;
        }
        mp["JD"]=1.0;
        double ans=0.0;
        for(int i=0;i<n;i++)
        {
            double x;
            string s;
            cin>>x>>s;
            ans+=mp[s]*x;
        }
        cout<<fixed<<setprecision(6)<<ans<<endl;
        mp.clear();
    }
 	return 0;
}
