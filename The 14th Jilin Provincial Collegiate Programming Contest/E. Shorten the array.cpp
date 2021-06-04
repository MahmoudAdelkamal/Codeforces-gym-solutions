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
const int N = 1e6+5;
const int mod = 1e9+7;
int a[N];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        bool flag = 0;
        int n,mini=1e9,ans = 0;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i],mini = min(mini,a[i]);
        for(int i=0;i<n;i++)
        {
            if(a[i]%mini!=0)
                flag = 1;
            if(a[i]==mini)
                ans++;
        }
        if(flag)
            cout<<1<<'\n';
        else
            cout<<(ans+1)/2<<'\n';
    }
 
    return 0;
}