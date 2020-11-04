#include <bits/stdc++.h>
#define de7k_gamed ios_base::sync_with_stdio(false);cin.tie(NULL);//freopen("out.txt","w",stdout);
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll a[101][101];
        for (ll i=0;i<n;i++)
            for (ll j=0;j<n;j++)
                cin>>a[i][j];
        pair<ll,ll> cur={0,0};
        vector<ll> v;
        bool up=true;
        while(true)
        {
            v.push_back(a[cur.first][cur.second]);
            if (cur.first==n-1 && cur.second==n-1)
                break;
            if (up)
            {
                if(cur.first-1>=0 && cur.second+1<n)
                    cur.first--,cur.second++;
                else if (cur.second+1<n)
                    cur.second++,up=false;
                else
                    cur.first++,up=false;
            }
            else
            {
                if(cur.second-1>=0 && cur.first+1<n)
                    cur.second--,cur.first++;
                else if (cur.first+1<n)
                    cur.first++,up=true;
                else
                    cur.second++,up=true;
            }
        }
        for(ll i=0;i<n;i++)
        {
            for (ll j=0;j<n;j++)
            {
                cout<<v[i*n +j];
                if (j<n-1)
                    cout<<' ';
            }
            cout<<'\n';
        }
    }
    return 0;
}
