#include <bits/stdc++.h>
#define de7k_gamed ios_base::sync_with_stdio(false);cin.tie(NULL);//freopen("out.txt","w",stdout);
typedef long long ll;
typedef long double ld;
#define pi acos(-1)
using namespace std;
const ll neg=-1 * 1e9;
unordered_map<char,bool>k;
string s;
ll dp[1000][1000][2];
ll solve(ll l,ll r,bool take)
{
    if(l>r)
        return 0;

    if(l==r)
    {
        if (k[s[l]])
            return 1;
        return neg;
    }
    if(dp[l][r][take]!=-1)
        return dp[l][r][take];
    ll choice=neg;
    if(s[l]==s[r]&& k[s[l]] && k[s[r]])
        choice=solve(l+1,r-1,true)+2;
    if(!take)
        return dp[l][r][take]=max(choice,max(solve(l+1,r,false),solve(l,r-1,false)));
    return dp[l][r][take]=choice;
}

int main()
{
    de7k_gamed;
    k['A']=k['H']=k['I']=k['M']=k['O']=k['T']=k['U']=k['V']=k['W']=k['X']=k['Y']=true;
    ll t;
    cin>>t;
    while(t--)
    {
       memset(dp,-1,sizeof dp);
       cin>>s;
       ll ans=solve(0,s.size()-1,false);
       cout<<max(ans,(ll)0)<<'\n';
    }
    return 0;
}
