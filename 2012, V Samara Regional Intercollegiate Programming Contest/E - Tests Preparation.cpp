#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <iomanip>
#include <set>
using namespace std;
#define ll long long
const int mod = 1000000007;
const int N = 1e5+5;
ll n,m,arr[N];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        for(int j=0;j<k;j++)
        {
            int x;
            cin>>x;
            arr[i]|=(1LL<<x);
        }
    }
    int res = 1e9;
    vector<int>Ans;
    for(int i=0;i<(1<<n);i++)
    {
        vector<int>ans;
        ll tmp = 0;
        for(int j=0;j<n;j++)
        {
            if((1<<j)&i)
            {
                ans.push_back(j);
                tmp|=arr[j];
            }
        }
        if(__builtin_popcountll(tmp)==m)
        {
            if(res>ans.size())
            {
                res = ans.size();
                Ans = ans;
            }
        }
    }
    cout<<Ans.size()<<endl;
    for(auto i:Ans)
        cout<<i+1<<" ";

    return 0;
}