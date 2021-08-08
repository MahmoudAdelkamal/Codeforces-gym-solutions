#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    vector<int>ans;
    int n,m,maxi=1,idx=0;
	cin>>n>>m;
	vector<pair<pair<int,int>,int>>v;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		v.push_back({{a,b},i});
	}
	sort(v.begin(),v.end());
	while(maxi<=m && idx<n)
	{
		pair<int,int>cur;
		cur.first=0,cur.second=0;
		while(idx<n && v[idx].first.first<=maxi)
		{
			cur=max(cur,{v[idx].first.second,v[idx].second});
			idx++;
		}
		if(cur.first<maxi)
            return cout<<"NO",0;
		maxi=cur.first+1;
		ans.push_back(cur.second);
	}
	if(maxi<=m)
        return cout<<"NO",0;
    cout<<"YES"<<endl<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}