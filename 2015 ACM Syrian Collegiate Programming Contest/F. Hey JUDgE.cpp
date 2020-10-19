#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=1e5+5;
const ll mod=1000000007;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<int>v;
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++)
        {
            v.push_back(s[i]-'A'+1);
        }
        bool valid = 0;
        sort(v.begin(),v.end());
        do
        {
            int ans = 1;
            int cur = 0;
            for(int i=0;i<v.size();i++)
            {
                if(cur==ans)
                    ans++,cur=0;
                cur+=v[i];
            }
            if(cur==ans)
                ans++,cur=0;
            if(ans>5)
                valid = 1;
        }
        while(next_permutation(v.begin(),v.end()));
        if(valid)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
   return 0;
}
