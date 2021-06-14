#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <iomanip>
#include <map>
#include <queue>
#include <utility>
#include <stack>
#include <unordered_map>
#define ll long long
using namespace std;
const int N = 1e6+5;
const int mod = 1e9+7;
bool isPrime[N];
vector < ll > vec;
void sieve()
{
    isPrime[1]=isPrime[0]=1;
    for(ll i=2;i<N;i++)
    {
        if(!isPrime[i])
        {
            vec.push_back(i);
            //  cout << i << endl;
            for(ll j=i+i;j<N;j+=i)
            {
                isPrime[j]=1;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sieve();
    int t;
    cin>>t;
    while(t--)
    {
        ll k;
        cin>>k;
        bool ok=0;
        vector<ll>ans;
        for(auto e:vec)
        {
 
            if(e!=2 && (k+2)%e==0)
            {
                ans.push_back(e);
                ok=1;
            }
        }
        for(int i=0;i<ans.size();i++) {
            if (i == ans.size() - 1) {
                cout << ans[i] << endl;
            } else
                cout << ans[i] << " ";
        }
        if(!ok)
            cout << -1 << endl;
    }
    return 0;
}