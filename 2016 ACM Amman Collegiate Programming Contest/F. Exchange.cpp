#include <bits/stdc++.h>
#define de7k_gamed ios_base::sync_with_stdio(false);cin.tie(NULL);//freopen("out.txt","w",stdout);
typedef long long ll;
typedef long double ld;
using namespace std;
int main()
{
    de7k_gamed;
    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int fo[30];
        for (int i=0;i<30;i++)
            fo[i]=1e6;
        for (int i=0;i<s.size();i++)
            fo[s[i]-'a']=min(fo[s[i]-'a'],i);
        pair<char,char> ans={'#','#'};
        for (char i='a';i<='z';i++)
        {
            if (fo[i-'a']==1e6)
                continue;
            char mni=i;
            for (char j=i+1;j<='z';j++)
            {
                if (fo[mni-'a']>fo[j-'a'])
                    mni=j;
            }
            if (mni!=i)
            {
                ans={i,mni};
                break;
            }
        }
        for (ll i=0;i<s.size();i++)
        {
            if (s[i]==ans.first)
                cout<<ans.second;
            else if (s[i]==ans.second)
                cout<<ans.first;
            else
                cout<<s[i];
        }
        cout<<'\n';
    }
    return 0;
}
