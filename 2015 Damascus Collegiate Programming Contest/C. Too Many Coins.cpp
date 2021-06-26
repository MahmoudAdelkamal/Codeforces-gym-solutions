#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#define ll long long
using namespace std;
const int N = 1e6+5;
const int mod = 1e9+7;
int a[N],cnt[N];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll cur = 0;
        set<int>st;
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            cnt[a[i]]++;
        }
        vector<pair<ll,ll>>v;
        for(int i=0;i<n;i++)
        {
            if (cnt[a[i]])
            {
                v.push_back({1ll*a[i]*cnt[a[i]],a[i]});
                cnt[a[i]] = 0;
            }
        }
        sort(v.rbegin(),v.rend());
        for(int i=0;i<v.size();i++)
        {
            cur+=v[i].first;
            st.insert(v[i].second);
            if(cur>=m)
                break;
        }
        if(cur>=m)
        {
            for(auto i:st)
                cout<<i<<' ';
            cout<<'\n';
        }
        else
            cout<<"Impossible\n";
    }
    return 0;
}