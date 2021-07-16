#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <iomanip>
#include <map>
#include <queue>
#include <utility>
#include <stack>
#include <unordered_map>
#define ll long long
using namespace std;
const int N = 1e5+5;
const int mod = 1e9+7;
int main()
{
    map<string,ll>mp;
    int t;
    cin>>t;
    while(t--)
    {
        map<char,char>mop;
        string s;
        cin>>s;
        for(char i='a';i<='z';i++)
            mop[i] = '#';
        char x = 'a';
        for(int i=0;i<s.size();i++)
        {
            if(mop[s[i]]=='#')
            {
                mop[s[i]] = x;
                x++;
            }
            s[i] = mop[s[i]];
        }
        mp[s]++;
    }
    ll ans = 0;
    for(auto i:mp)
        ans+=1LL*((i.second)*(i.second-1))/2;
    cout<<ans<<"\n";
    return 0;
}