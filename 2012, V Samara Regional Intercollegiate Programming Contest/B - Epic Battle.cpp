#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <iomanip>
#include <set>
using namespace std;
#define ll long long
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,a[50],sum = 0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i],a[i]--;
    for(int i=0;i<n;i++)
        sum+=a[i];
    if(sum%2)
        cout<<"Constantine";
    else
        cout<<"Mike";
    return 0;
}