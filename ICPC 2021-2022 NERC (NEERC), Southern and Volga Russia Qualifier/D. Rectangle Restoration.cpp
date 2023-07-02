#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#define  ll long double
using namespace std;
const int N = 2e5+5;
ll perimeter(ll s1,ll s2)
{
    return s1+s1+s2+s2;
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);

   /* cin >> n; int u,v;

    for(int i = 0 ; i < n - 1 ; i++){

        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1 , -1);

    if(startNode == -1){
        cout << "NO";;
        return 0;
    }
    cout << "YES\n";

    color(startNode ,-1, parOfStartNode);
    col[startNode] = 1;
    for(int i = 1; i <= n ; i++){
        cout << col[i] << " ";
    }
    */
    ll x,y,ans = 2e9;
    cin>>x>>y;
   // case 1
   ll s1 = (y-x);
   ll s2 = (x-s1);
   if(s1>0 && s2>0)
   {
        ans = min(ans, perimeter(s1,s2));
   }

   // case 2
   s1 = x/2.0;
   s2 = y-(s1+s1);
   if(s1>0 && s2>0)
   {
       ans = min(ans, perimeter(s1,s2));
   }


   // case 3
   s2 = x/2.0;
   s1 = (y-s2)/2.0;
   if(s1>0 && s2>0)
   {
       ans = min(ans, perimeter(s1,s2));
   }
   if(ans==2e9)
       return cout<<-1,0;
   cout<<fixed<<setprecision(6)<<ans<<endl;
   return 0;
}