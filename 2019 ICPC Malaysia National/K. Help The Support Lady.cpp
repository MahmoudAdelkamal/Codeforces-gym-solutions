#include <bits/stdc++.h>
#define  ll long long
#define endl "\n"
using namespace std;
const int N=1e5+5;
ll a[N];
int main()
{
    int t,test = 0;
    cin>>t;
    while(t--)
    {
        test++;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        ll sum = a[0],cnt = 1;
        for(int i=1;i<n;i++)
        {
            if(sum<=a[i])
            {
                sum+=a[i];
                cnt++;
            }
        }
        cout<<"Case #"<<test<<": "<<cnt<<endl;
    }

    return 0;
}