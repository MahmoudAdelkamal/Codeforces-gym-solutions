#include <bits/stdc++.h>
#define de7k_gamed ios_base::sync_with_stdio(false);cin.tie(NULL);//freopen("out.txt","w",stdout);
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
int main()
{
    ld x,y,x1,y1,x2,y2;
    cin>>x>>y>>x1>>y1>>x2>>y2;
    pair<ld,ld>c1,c2,c3,c4;
    c1={max(min(max(x1,x2),x) ,min(x1,x2)),max(min(y1,y) ,y1)};
    c2={max(min(x1,x) ,x1),max(min(max(y1,y2),y) ,min(y1,y2))};
    c3={max(min(x2,x) ,x2),max(min(max(y1,y2),y) ,min(y1,y2))};
    c4={max(min(max(x1,x2),x) ,min(x1,x2)),max(min(y2,y) ,y2)};
    ld ans=sqrt((c1.first-x)*(c1.first-x) + (c1.second-y)*(c1.second-y));
    ans=min(ans,sqrt((c2.first-x)*(c2.first-x) + (c2.second-y)*(c2.second-y)) );
    ans=min(ans,sqrt((c3.first-x)*(c3.first-x) + (c3.second-y)*(c3.second-y)) );
    ans=min(ans,sqrt((c4.first-x)*(c4.first-x) + (c4.second-y)*(c4.second-y)) );
    cout<<fixed<<setprecision(3)<<ans;
    return 0;
}
