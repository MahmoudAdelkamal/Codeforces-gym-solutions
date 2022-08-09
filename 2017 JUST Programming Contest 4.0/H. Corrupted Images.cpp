#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int N=1e6+5;
const int mod=1e9+7;
int n,m;
char a[55][55];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        }
        int zeros = 0,ones = 0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if((i==1 || i==n || j==1 || j==m))
                {
                    if(a[i][j]=='0')
                       zeros++;
                }
                else if(a[i][j]=='1')
                    ones++;
            }
        }
        if(ones>=zeros)
            cout<<zeros<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}