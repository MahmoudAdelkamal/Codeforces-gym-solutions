#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
const int N=55;
int main()
{
    map<char,int>mp;
    string s,ans;
    cin>>s;
    for(int i=0;i<s.size();i++)
         mp[s[i]]++;
    for(char i='a';i<='z';i++)
    {
        int cnt = mp[i]/2;
        int rem = mp[i]%2;
        if(i=='z')
            cnt=0,rem=mp[i];
        while(cnt--)
        {
            mp[i+1]++;
        }
        while(rem--)
        {
            ans.push_back(i);
        }
    }
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}
