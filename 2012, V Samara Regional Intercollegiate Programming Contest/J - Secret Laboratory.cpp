#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <iomanip>
#include <set>
using namespace std;
#define ll long long
const int mod = 1000000007;
const int N = 1e3+1;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    map<char,int>mp;
    string s;
    int k,j = 0,maxi = 0;
    cin>>k>>s;
    pair<int,int>ans = {0,0};
    for(int i=0;i<s.size();i++)
    {
        while(j<s.size() && mp.size()<=k)
        {
            mp[s[j]]++;
            j++;
        }
        if(j==s.size() && mp.size()<=k)
        {
            if(j-i > maxi)
            {
                maxi = j-i;
                ans.first = i;
                ans.second = j;
            }
        }
        else if(j-i-1 > maxi)
        {
            maxi = j-i-1;
            ans.first = i;
            ans.second = j-1;

        }
        mp[s[i]]--;
        if(!mp[s[i]])
            mp.erase(s[i]);
    }
    cout<<ans.first+1<<" "<<ans.second<<endl;
    return 0;
}