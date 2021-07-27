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
ll n,ans = 1,j=9;
int main()
{
    ll x1,x2,x3,x4,h;
    cin>>x1>>x2>>x3>>x4>>h;
    ll x = max(0LL,min(x2,x4)-max(x1,x3));
    cout<<x*1LL*h<<endl;
    return 0;
}