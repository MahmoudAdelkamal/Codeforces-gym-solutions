#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=3e5+5;
const ll mod=1000000007;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int x,y,n,q;
        int winner = 1,ans = 0;
        cin>>n>>q;
        int team[n+1]={0};
        set<pair<int,int>>st;
        for(int i=1;i<=n;i++)
            st.insert({0,i});
        for(int i=0;i<q;i++)
        {
            cin>>x>>y;
            st.erase({-team[x],x});
            team[x]+=y;
            st.insert({-team[x],x});
            int tmp=(*st.begin()).second;
            if(tmp!=winner)
            {
                winner=tmp;
                ans=i+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
