#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=1e5+5;
const ll mod=1000000007;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        map<string,vector<pair<int,int>>>mp;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            string s;
            int a,b,x;
            cin>>s>>a>>b>>x;
            for(int j=0;j<x;j++)
            {
                string name;
                cin>>name;
                mp[name].push_back({a,b});
            }
        }
        vector<string>ans;
        for(auto i:mp)
        {
            sort(i.second.begin(),i.second.end());
            for(int j=1;j<i.second.size();j++)
            {
                if(i.second[j].first<=i.second[j-1].second)
                {
                    ans.push_back(i.first);
                    break;
                }
            }
        }
        sort(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
            cout<<ans[i]<<endl;
    }
   return 0;
}
