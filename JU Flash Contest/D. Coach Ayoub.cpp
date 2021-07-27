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
int main()
{
    int n,a,b,s;
    cin>>n>>a>>b>>s;
    ll val1 = (n-1)*a+b;
    ll val2 = (n-1)*b+a;
    if(val1>s || val2<s)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;
    return 0;
}