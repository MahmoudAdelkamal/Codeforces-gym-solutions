#include<iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 1e5+5;
const int mod = 1e9+7;
int main()
{
    char a[55][55];
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    }
    for(int j=0;j<m;j++)
    {
        int prv = n-1;
        for(int i=n-1;i>=0;i--)
        {
            // Not a valid place to swap, replace it with the upper one
            if(a[i][j]=='#')
                prv = i-1;
            // Swap yasta
            if(a[i][j]=='o')
            {
                swap(a[prv][j],a[i][j]);
                prv--;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<a[i][j];
        cout<<endl;
    }
    return 0;
}