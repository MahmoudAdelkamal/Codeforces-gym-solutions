#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=1e5+5;
const ll mod=1000000007;
map<string,int>mp;
int main()
{
    mp["Alice"]=mp["Ariel"]=mp["Phil"]=mp["Peter"]=mp["Olaf"]=mp["Phoebus"]=mp["Ralph"]=mp["Robin"]=mp["Aurora"]=0;
    mp["Bambi"]=mp["Belle"]=mp["Bolt"]=mp["Mulan"]=mp["Mowgli"]=mp["Mickey"]=mp["Silver"]=mp["Simba"]=mp["Stitch"]=1;
    mp["Dumbo"]=mp["Genie"]=mp["Jiminy"]=mp["Kuzko"]=mp["Kida"]=mp["Kenai"]=mp["Tarzan"]=mp["Tiana"]=mp["Winnie"]=2;
    int n,ans=0,c=0;
    cin>>n;
    while(n--)
    {
        string s;
        cin>>s;
        ans+=abs(c-mp[s]);
        c=mp[s];
    }
    cout<<ans;
    return 0;
}
