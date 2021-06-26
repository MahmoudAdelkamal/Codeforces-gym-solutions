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
const int N = 2e5+5;
const int mod = 1e9+9;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        ll n,min_x = INT_MAX, max_x = INT_MIN, min_y = INT_MAX, max_y = INT_MIN;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            for(int i=0;i<4;i++)
            {
                ll x,y;
                cin>>x>>y;
                min_x = min(min_x,x);
                max_x = max(max_x,x);
                min_y = min(min_y,y);
                max_y = max(max_y,y);
            }
        }
        cout<<abs(max_x-min_x)*abs(max_y-min_y)<<endl;
    }
    return 0;
}