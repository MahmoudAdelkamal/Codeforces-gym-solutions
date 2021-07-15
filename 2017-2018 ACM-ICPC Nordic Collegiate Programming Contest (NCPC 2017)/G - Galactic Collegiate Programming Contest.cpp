#include<iostream>
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <cmath>
using namespace std;
#define ll long long
const int N=1e5+5;
vector<pair<int,int>>v(N);
set<pair<pair<int,int>,int>>st;
int main()
{
    int n,m;
    cin>>n>>m;
    while (m--)
    {
        int t,p;
        cin>>t>>p;
        st.erase({v[t],t});
        v[t].first++;
        v[t].second-=p;
        if(t==1)
        {
            auto it=st.begin();
            while(it!=st.end() && it->first<=v[1])
                  st.erase(it++);
        }
        else
        {
            if(v[t]>v[1])
                st.insert({v[t],t});
        }
        cout<<st.size()+1<<endl;
    }
    return 0;
}
