#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int N=3e5+5;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        map<char,bool>row,col,p,n;
        bool valid=1;
        for(int i=0;i<8;i++)
        {
            char x,y;
            cin>>x>>y;
            if(row[x] || col[y] || p[x+y] || n[x-y])
            {
                valid=0;
                break;
            }
            row[x]=col[y]=p[x+y]=n[x-y]=1;
        }
        if(valid)
          cout<<"Valid"<<endl;
        else
          cout<<"Invalid"<<endl;
    }
    return 0;
}
