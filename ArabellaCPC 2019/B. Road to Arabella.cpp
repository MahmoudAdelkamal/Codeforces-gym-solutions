#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
const int N=55;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        if(k>=n-1)
        {
            if(n%2==0)
                cout<<"Ayoub"<<endl;
            else
                cout<<"Kilani"<<endl;
        }
        else
        {
            cout<<"Kilani"<<endl;
        }
    }
    return 0;
}
