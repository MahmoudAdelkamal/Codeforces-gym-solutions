#include<iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 1e5+5;
const int mod = 1e9+7;
int n,m;
char arr[55][55];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
void dfs(int i,int j)
{
    if(i<0 || i>=n || j<0 || j>=m)
        return;
    if(arr[i][j]=='W')
        return;
    arr[i][j] = 'W';
    for(int k=0;k<4;k++)
    {
        int x = i+dx[k];
        int y = j+dy[k];
        dfs(x,y);
    }
}
int main()
{
    ll ans = 0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]=='L')
            {
               ans++;
               dfs(i,j);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}