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
string a,b;
set<string>st;
void solve(int idx_a,int idx_b,string s)
{
    if(idx_a==a.size() && idx_b==b.size())
    {
        st.insert(s);
        return ;
    }
    if(idx_a+1<=a.size())
    {
        s.push_back(a[idx_a]);
        solve(idx_a+1,idx_b,s);
        s.pop_back();
    }
    if(idx_b+1<=b.size())
    {
        s.push_back(b[idx_b]);
        solve(idx_a,idx_b+1,s);
        s.pop_back();
    }
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        st.clear();
        cin>>a>>b;
        solve(0,0,"");
        for(auto i:st)
            cout<<i<<endl;
        cout<<endl;
    }
    return 0;
}