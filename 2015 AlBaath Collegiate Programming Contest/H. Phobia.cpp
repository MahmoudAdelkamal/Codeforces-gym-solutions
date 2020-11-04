#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int N=3e5+5;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n,m;
bool valid(int i,int j)
{
    return (i>=1 && i<=n && j>=1 && j<=m);
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        pair<int,int>en;
        queue<pair<int,int>>q1,q2;
        char a[105][105];
        ll cost1[105][105],cost2[105][105];
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>a[i][j];
                if(a[i][j]=='*')
                    cost1[i][j]=0,q1.push({i,j});
                else
                    cost1[i][j]=1e18;
                if(a[i][j]=='S')
                    cost2[i][j]=0,q2.push({i,j});
                else
                    cost2[i][j]=1e18;
                if(a[i][j]=='X')
                    en={i,j};
            }
        }
      while(!q1.empty())
      {
          int x=q1.front().first,y=q1.front().second;
          q1.pop();
          for(int i=0;i<4;i++)
          {
              int newx = x+dx[i];
              int newy = y+dy[i];
              if(valid(newx,newy) && a[newx][newy]!='#' && cost1[newx][newy]>cost1[x][y]+1)
              {
                  cost1[newx][newy]=cost1[x][y]+1;
                  q1.push({newx,newy});
              }
          }
      }
      while(!q2.empty())
      {
          int x=q2.front().first,y=q2.front().second;
          q2.pop();
          for(int i=0;i<4;i++)
          {
              int newx = x+dx[i];
              int newy = y+dy[i];
              if(valid(newx,newy) && a[newx][newy]!='#' && cost2[newx][newy]>cost2[x][y]+1 && cost2[x][y]+1<cost1[newx][newy])
              {
                  cost2[newx][newy]=cost2[x][y]+1;
                  q2.push({newx,newy});
              }
          }
      }
      if(cost2[en.first][en.second]!=1e18)
         cout<<"yes"<<endl;
      else
         cout<<"no"<<endl;
    }
    return 0;
}
