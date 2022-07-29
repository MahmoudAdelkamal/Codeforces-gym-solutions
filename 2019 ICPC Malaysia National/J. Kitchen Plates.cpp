#include <bits/stdc++.h>
#define  ll long long
#define endl "\n"
using namespace std;
const int N=1e5+5;
vector<vector<int>>adj(N);
int vis[N];
int main()
{
    queue<int>q;
    for(int i=0;i<5;i++)
    {
        string s;
        cin>>s;
        if(s[1]=='>')
            swap(s[0],s[2]);
        adj[s[0]-'A'].push_back(s[2]-'A');
        vis[s[2]-'A']++;
    }
    for(char i='A';i<='E';i++)
    {
        if(!vis[i-'A'])
            q.push(i-'A');
    }
    string ans = "";
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        ans+=cur+'A';
        for(int i=0;i<adj[cur].size();i++)
        {
            vis[adj[cur][i]]--;
            if(!vis[adj[cur][i]])
                q.push(adj[cur][i]);
        }
    }
    if(ans.size()!=5)
        ans = "impossible";
    cout<<ans<<endl;
    return 0;
}