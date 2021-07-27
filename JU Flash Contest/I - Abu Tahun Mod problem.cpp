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
const int N = 2e5+5;
int arr[N];
int main()
{
    bool flag = 0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=1;i<=n/2;i++)
        arr[i]=abs(arr[n-i+1]-arr[i]);
    for(int i=1;i<=n/2;i++)
    {
        if(arr[i]!=0)
            flag=1;
    }
    if(!flag)
        return cout<<-1,0;
    int ans = arr[1];
    for(int i=2;i<=n/2;i++)
        ans=__gcd(ans,arr[i]);
    cout<<ans;
    return 0;
}