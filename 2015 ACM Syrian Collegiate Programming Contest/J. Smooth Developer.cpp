#include <bits/stdc++.h>
#include <unordered_map>
#define ReadFile freopen("input.txt","r",stdin); // matnsash deh ';'
#define ReadFiles freopen("string.in","r",stdin);
#define WriteFile freopen("output.txt","w",stdout); // matnsash deh ';'
#define MEGA_MIND ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define M_PI 3.14159265358979323846
#define mod 1000000007
#define endl "\n"
#define point complex<ld>
using namespace std;
using ll = long long;
using lli = long long int;
using ld = long double;
const int N = 1e5 + 5, inf = 2e9;
int n,k;
unordered_map<string, vector<string>> adj;
unordered_map<string, bool> visited;
vector<string>v;
void dfs(string s)
{
	visited[s] = 1;
	for (auto child : adj[s])
	{
		if (!visited[child])
			dfs(child);
	}
}
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		cin>>n>>k;
		while(n--)
		{
			string s;
            cin>>s;
			v.push_back(s);
			int x;
            cin>>x;
			while(x--)
			{
				string e;
                cin>>e;
				adj[s].push_back(e);
			}
		}
		while (k--)
		{
			string s;
			cin>>s;
			if(!visited[s])
				dfs(s);
		}
		for(auto i:v)
            if(visited[i])
                cout<<i<<'\n';
        v.clear();
		visited.clear();
		adj.clear();
	}
	return 0;
}
