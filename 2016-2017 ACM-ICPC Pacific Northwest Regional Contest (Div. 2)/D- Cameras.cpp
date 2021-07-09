#include <bits/stdc++.h>
 
#define sr3 ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
const int N = 2e5 + 5, inf = 2e9, mod = 1e9 + 7;
 
 
int main() {
    sr3
    ll n,k,r,ans=0;
    cin>>n>>k>>r;
    priority_queue<ll, vector<ll>, greater<>>collector;
    ll arr[n+5]={};
    for(int i=0,x; i<k&&cin>>x; i++)
        arr[x]=1;
    for(int i=2; i<=n; i++)
        arr[i]+=arr[i-1];
 
    for(int i=r; i<=n; i++){
        while(collector.size()&&collector.top()<i-r+1)collector.pop();
        if(arr[i]-arr[i-r]+collector.size()>=2)continue;
        if(arr[i]-arr[i-r]+collector.size()==1){
            ans+=1;
            for(int j=i; j>0; j--)
                if(arr[j]==arr[j-1]){
                        collector.push(j);
                        break;
                }
        }
        else {
            int it=0;
            ans+=2;
            for(int j=i; j>0; j--){
                if(it==2)break;
                if(arr[j]==arr[j-1]){
                    it++,collector.push(j);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}