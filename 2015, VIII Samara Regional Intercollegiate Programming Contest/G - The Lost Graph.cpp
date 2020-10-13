#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=2e5+5;
const int mod=1e9+7;
int main()
{
    vector<pair<ll,ll>>ans;
    stack<ll>st;
    ll n;
    cin>>n;
    for(ll i=0;i<2*n;i++)
    {
        string s;
        ll x;
        cin>>s>>x;
        if(s=="in")
        {
            if(!st.empty())
            {
                ans.push_back({st.top(),x});
            }
            st.push(x);
        }
        else
        {
            st.pop();
        }
    }
    for(ll i=0;i<ans.size();i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    return 0;
}
