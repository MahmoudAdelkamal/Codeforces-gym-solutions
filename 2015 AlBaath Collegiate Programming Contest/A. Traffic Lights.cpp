#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int N=3e5+5;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll x,g,y,r;
        cin>>x>>g>>y>>r;
        x%=(g+y+r);
        if(x<g)
        {
            cout<<"GREEN"<<endl;
            continue;
        }
        else
            x-=g;
        if(x<y)
        {
            cout<<"YELLOW"<<endl;
            continue;
        }
        else
            x-=y;
        cout<<"RED"<<endl;
    }
    return 0;
}
