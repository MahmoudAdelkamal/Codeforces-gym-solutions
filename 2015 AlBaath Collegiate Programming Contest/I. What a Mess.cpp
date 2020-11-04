#include <bits/stdc++.h>
#define de7k_gamed ios_base::sync_with_stdio(false);cin.tie(NULL);//freopen("out.txt","w",stdout);
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
int freq[(ll)1e6 +5];
int main()
{
    de7k_gamed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin >> n;
        memset(freq ,0,sizeof freq);
        vector<int>v;
       for(int i=0;i<n;i++)
       {
           int x;cin >> x;
           if(freq[x]==0)
                v.push_back(x);
           freq[x]++;
       }
       int ans=0;
       for(int i=0;i<v.size();i++)
       {
           ans+=(freq[v[i]]*(freq[v[i]]-1))/2;
           for(int j=v[i]*2;j<1e6+1;j+=v[i])
           {
               ans+=freq[v[i]]*freq[j];
           }
       }
       cout << ans << endl;
    }
    return 0;
}
