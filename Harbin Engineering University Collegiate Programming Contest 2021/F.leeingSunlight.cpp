#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const int N = 2e5+5;
const double eps = 1e-9;
/*int n;
int solve(int idx,int prv)
{
    if(idx>n)
        return 0;
    if(idx==n)
    {
        if(prv==2)
            return 1;
        return 0;
    }
    int op1 = solve(idx+1,1);
    int op2 = solve(idx+2,2);
    return op1+op2;
}*/
int main()
{
    /*int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<solve(0,1)<<" "<<solve(0,2)<<endl;
    }*/
    int n,m;cin >> n>> m;
    vector<pair<ld,ld>>v;
    for(int i=0;i<n;i++)
    {
        pair<ld,ld>pr;

        cin >> pr.first >> pr.second;

         v.push_back(pr);

    }

    ld mid,ans,l=0,r=1e9+5;
    while(r-l>eps)
    {
        mid=(r+l)/2;
        ld val=0;
        for(auto i:v)
        {
            if(mid>=i.second)
                val=val+1;
            else if(mid>=i.first)
                val+=(mid-i.first)/(i.second-i.first);
        }
        if(val>=m)
            r=ans=mid;
        else l=mid;
    }
    cout << fixed << setprecision(9) << ans << endl;

    return 0;
}
