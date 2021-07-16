#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <iomanip>
#include <map>
#include <queue>
#include <utility>
#include <stack>
#include <unordered_map>
#define ll long long
using namespace std;
const int N = 1e5+5;
const int mod = 1e9+7;
int main()
{
    int t,a,b;
    cin>>t;
    t--;
    cin>>a>>b;
    int last = a,ans = b;
    while (t--)
    {
        int a,b;
        cin>>a>>b;
        if(a>last)
        {
            last = a;
            ans = max(ans,b);
        }
    }
    cout<<ans<<endl;
    return 0;
}