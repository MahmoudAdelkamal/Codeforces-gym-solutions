#include <bits/stdc++.h>

#define sr3 ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define ld long double
using namespace std;
const int N = 1e6 + 5, mod = 1e9 + 7;


int main() {
    sr3
    int n;
    double x,v,v1,tmp,l,r,vi;
    cin>>n>>x>>v;
    tmp = 0;
    for(int i=0; i<n; i++){
        cin>>l>>r>>vi;
        tmp+= (r-l)*vi;
    }
    v1 = tmp /x;
    if(fabs(v1)>v){
        cout<<"Too hard"<<endl;
    }
    else {
        double v2 = sqrt(v * v - v1 * v1);
        double ans = x/v2;
        cout<<fixed<<setprecision(3)<<ans<<endl;
    }
}