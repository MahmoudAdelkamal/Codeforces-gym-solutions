#include <bits/stdc++.h>
#define de7k_gamed ios_base::sync_with_stdio(false);cin.tie(NULL);//freopen("out.txt","w",stdout);
typedef long long ll;
typedef long double ld;
using namespace std;
int main()
{
    de7k_gamed
    map<char,bool>mp;
    mp['A']=mp['H']=mp['I']=mp['M']=mp['O']=mp['T']=mp['U']=mp['V']=mp['W']=mp['X']=mp['Y']=1;
    ll t;
    cin>>t;
    while(t--)
    {
        bool ok=1;
        string s;cin >> s;
        for(int i=0;i<s.size();i++)
        {
            if(!mp[s[i]])
            {
                ok=0;
                break;
            }
        }
        string t=s;
        reverse(s.begin(),s.end());
        if(ok && s==t)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
 	return 0;
}
