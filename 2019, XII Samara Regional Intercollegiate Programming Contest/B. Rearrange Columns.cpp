#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define ll long long
int main()
{
    bool flag=0;
	ll cnt1=0,cnt2=0,cnt3=0;
	string s1,s2;
	cin>>s1>>s2;
	for(ll i=0;i<s1.size();i++)
    {
        if(s1[i]=='#' && s2[i]=='#')
        {
           flag=1;
           cnt3++;
        }
        else if(s1[i]=='#')
            cnt1++;
        else if(s2[i]=='#')
            cnt2++;
    }
    if(!flag && (cnt1>0 && cnt2>0))
        return cout<<"NO",0;
    cout<<"YES"<<endl;
    for(ll i=0;i<cnt1;i++)
        cout<<"#";
    for(ll i=0;i<cnt3;i++)
        cout<<"#";
    for(ll i=0;i<s1.size()-(cnt1+cnt3);i++)
        cout<<".";
    cout<<endl;
    for(ll i=0;i<cnt1;i++)
        cout<<".";
    for(ll i=0;i<cnt3;i++)
        cout<<"#";
    for(ll i=0;i<cnt2;i++)
        cout<<"#";
    for(ll i=0;i<s2.size()-(cnt1+cnt2+cnt3);i++)
        cout<<".";
    return 0;
}