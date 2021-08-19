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
const int N = 1e3+1;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll n,k,cur = 1,cnt = 0;
    cin>>n>>k;
    ll tmp = k;
    while(cur<n)
    {
        cnt++;
        cur+=cur*k;
    }
    cout<<cnt<<endl;
    return 0;
}