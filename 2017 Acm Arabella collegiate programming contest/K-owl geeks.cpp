#include <bits/stdc++.h>
#define de7k_gamed ios_base::sync_with_stdio(false);cin.tie(NULL);//freopen("out.txt","w",stdout);
typedef long long ll;
typedef long double ld;
#define pi acos(-1)
using namespace std;
int main()
{
    de7k_gamed;
    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,n;
        cin>>a>>b>>n;
        ll freq[10]={};
        ll cnt=1;
        while(true)
        {
            ll sum=a*cnt*cnt+b*cnt;
            if(sum>n)
                break;
            ll arr[10]={},maxi=0;
            while(sum)
            {
                arr[sum%10]++;
                sum/=10;
            }
            for(int i=0;i<10;i++)
            {
                maxi=max(maxi,arr[i]);
            }
            for(int i=0;i<10;i++)
            {
                if(arr[i]==maxi)
                {
                    freq[i]++;
                }
            }
            cnt++;
        }
        ll maxi=0,ans=-1;
        for(int i=0;i<10;i++)
        {
            maxi=max(maxi,freq[i]);
        }
        for(int i=0;i<10;i++)
        {
            if(freq[i]==maxi &&maxi!=0)
            {
                ans=i;
                break;
            }
        }
        cout<<ans<<endl;
    }
 	return 0;
}
