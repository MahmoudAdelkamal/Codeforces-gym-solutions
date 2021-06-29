#include<iostream>
#include<string>
#include <map>
#include <iomanip>
#include <cmath>
#define ll long long
using namespace std;
const int N = 70;
string name[N];
int n;
double floyd[N][N],x[N],y[N],z[N];
double dist(int i,int j)
{
    return (sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j])));
}
int main()
{
    int q,t = 0;
    cin>>q;
    while(q--)
    {
        cout<<"Case "<<++t<<":\n";
        cin>>n;
        map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            cin>>name[i]>>x[i]>>y[i]>>z[i];
            mp[name[i]] = i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                floyd[i][j] = dist(i,j);
        }
        int w;
        cin>>w;
        while(w--)
        {
            string u,v;
            cin>>u>>v;
            floyd[mp[u]][mp[v]] = 0;
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    floyd[i][j] = min(floyd[i][j],floyd[i][k]+floyd[k][j]);
            }
        }
        int T;
        cin>>T;
        while(T--)
        {
            string u,v;
            cin>>u>>v;
            int i = mp[u],j = mp[v];
            cout<<fixed<<setprecision(0)<<"The distance from "<< name[i]<<" to "<<name[j]<<" is "<<round(floyd[i][j])<<" parsecs.\n";
        }
    }
    return 0;
}