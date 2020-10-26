#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int N=55;
int main()
{
    int k,cnt1=0,cnt2=0;
    string s,t;
    cin>>k>>s>>t;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==t[i])
            cnt1++;
        else
            cnt2++;
    }
    cout<<min(cnt1,k)+min(cnt2,(int)s.size()-k);
}
