#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+5;
bool is_pali(string s)
{
    string tmp = s;
    reverse(s.begin(),s.end());
    return (s==tmp);
}
int main()
{
     string s;
     cin>>s;
     bool valid = 1;
     int n = s.size();
     for(int i=1;i<=n;i++)
     {
        for(int k=0;k+i<=n;k++)
        {
            bool is_pali = 1;
            for(int j=0;j<i;j++)
            {
                if (s[k+j]!=s[k+i-1-j])
                    is_pali = 0;
            }
            if(is_pali && i%2==0)
                valid = 0;
        }
      }
      if(valid)
        cout<<"Odd."<<endl;
      else
        cout<<"Or not."<<endl;
    return 0;
}
