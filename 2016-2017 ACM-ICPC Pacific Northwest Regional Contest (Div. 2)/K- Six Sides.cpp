#include <bits/stdc++.h>
 
#define sr3 ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
const int N = 2e5 + 5, inf = 2e9, mod = 1e9 + 7;
 
 
int main() {
    sr3
    int f[10],s[10] ;
    for(int i=0; i<6; i++)
        cin>>f[i];
    for(int i=0; i<6; i++)
        cin>>s[i];
    double win=0,tie=0,ans=0;
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if(f[i]>s[j])win++;
            else if(f[i]==s[j])tie++;
        }
    }
    ans=win/(36-tie);
    cout<<fixed<<setprecision(5);
    cout<<ans<<endl;
    return 0;
}