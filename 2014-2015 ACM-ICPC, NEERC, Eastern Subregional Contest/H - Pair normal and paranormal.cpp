#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=5e4+5;
const ll mod=1000000007;
int main()
{
    string s;
    stack<pair<char,int>>st;
    int n,ans[N],c1=0,c2=0;
    cin>>n>>s;
    for(int i=0;i<2*n;i++)
    {
        if(s[i]>='A' && s[i]<='Z')
        {
            c1++;
            if((st.empty()) || (s[i]+32!=st.top().first))
            {
                st.push({s[i],c1});
            }
            else
            {
                ans[c1]=st.top().second;
                st.pop();
            }
        }
        else
        {
            c2++;
            if(st.empty() || (s[i]-32!=st.top().first))
            {
                st.push({s[i],c2});
            }
            else
            {
                ans[st.top().second]=c2;
                st.pop();
            }
        }
    }
    if(!st.empty())
        cout<<"Impossible"<<endl;
    else
    {
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<" ";
    }
    return 0;
}
