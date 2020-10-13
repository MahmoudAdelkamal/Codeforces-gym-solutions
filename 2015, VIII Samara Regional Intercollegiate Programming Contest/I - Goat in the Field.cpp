#include <bits/stdc++.h>
#define de7k_gamed ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef long long ll;
typedef long double ld;
using namespace std;
int main()
{
    pair<pair<int,int>,string>p[1500];
    int x,y,n,dx=0,dy=0;
    cin>>x>>y;
    string s;
    cin>>s>>n;
    if(s=="LEFT")
        dx=-1;
    else if(s=="RIGHT")
        dx=1;
    else if(s=="UP")
        dy=1;
    else
        dy=-1;
    for(int i=0;i<n;i++)
    {
        cin>>p[i].second;
        cin>>p[i].first.first>>p[i].first.second;
    }
    for(int i=0;i<=100000;i++)
    {
        int posx = x+dx*i;
        int posy = y+dy*i;
        for(int j=0;j<n;j++)
        {
            int distx = abs(posx-p[j].first.first);
            int disty = abs(posy-p[j].first.second);
            if((distx+1)/2+(disty+1)/2<=i)
            {
                return cout<<p[j].second,0;
            }
        }
    }
 	return 0;
}
