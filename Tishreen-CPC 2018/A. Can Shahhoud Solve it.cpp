#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int main()
{
    ll t,s,d;
    cin>>t;
    while(t--){
        cin>>s>>d;
        if(s>=d)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
  return 0;
}
