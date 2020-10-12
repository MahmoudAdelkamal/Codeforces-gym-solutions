#include <bits/stdc++.h>
#define de7k_gamed ios_base::sync_with_stdio(false);cin.tie(NULL);//freopen("out.txt","w",stdout);
typedef long long ll;
typedef long double ld;
#define pi acos(-1)
using namespace std;
ll arr[(ll)1e5+5];
int main()
{
    de7k_gamed
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n==2 || n==3)
            cout<<"second"<<endl;
        else
            cout<<"first"<<endl;
    }
 	return 0;
}
