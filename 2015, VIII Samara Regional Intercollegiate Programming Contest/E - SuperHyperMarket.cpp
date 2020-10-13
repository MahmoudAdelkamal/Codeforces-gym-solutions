#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=1e4+5;
const int mod=1e9+7;
int main()
{
    ll n,k;
    cin>>n>>k;
    priority_queue<pair<ld,vector<ld>>,vector<pair<ld,vector<ld>>>,greater<pair<ld,vector<ld>>> > pq;
    for (ld i=1;i<=k;i++)
    {
        vector<ld> tmp(4);
        tmp[3]=tmp[1]=-1;
        tmp[2]=0;
        tmp[0]=i;
        pq.push({0,tmp});
    }
    for (ld x,i=0;i<n;i++)
    {
        cin>>x;
        pair<ld,vector<ld>> tmp=pq.top();
        pq.pop();
        cout<<tmp.second[0]<<' ';
        tmp.second[1]=tmp.second[3];
        tmp.second[3]=x;
        tmp.second[2]++;
        if (tmp.second[2]==1)
            tmp.first=tmp.second[3];
        else
            tmp.first=tmp.second[2]*((tmp.second[3]+tmp.second[1])/2);
        pq.push(tmp);
    }
    return 0;
}
