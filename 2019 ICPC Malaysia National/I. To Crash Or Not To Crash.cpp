#include <bits/stdc++.h>
#define  ll long long
#define endl "\n"
using namespace std;
const int N=1e5+5;
string s[N];
int main()
{
     string ans = "You shall pass!!!";
    cin>>s[0]>>s[1]>>s[2];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<s[i].size();j++)
        {
            if(s[i][j]=='=')
            {
                for(int k=j+1;k<s[i].size();k++)
                {
                    if(s[i][k]!='.' && s[i][k]!='=')
                    {
                        ans = s[i][k];
                        break;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}