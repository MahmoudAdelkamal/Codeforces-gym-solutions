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
int main()
{
    int n,m,a[1005],b[1005],ans = 0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    int j = 0;
    for(int i=0;i<m;i++)
    {
        int sum = 0;
        while (sum+a[j]<=b[i] && j<n)
        {
            sum+=a[j];
            j++;
        }
        ans+=b[i]-sum;
    }
    cout<<ans;
    return 0;
}