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
    int n,m,k,arr[500],maxi = 0;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
        cin>>arr[i],maxi = max(maxi,arr[i]);
    if(k==0)
    {
        if(maxi==m)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(arr[i]>m)
                arr[i] = m,k--;
        }
        if(k<0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}