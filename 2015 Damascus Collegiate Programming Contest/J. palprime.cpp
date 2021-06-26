#include<iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#define ll long long
using namespace std;
const int N = 2e6+5;
const int mod = 1e9+9;
ll is_prime[N];
string to_bin(int x)
{
    string ans = "";
    while(x)
    {
        if(x%2==0)
            ans+='0';
        else
            ans+='1';
        x /= 2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int to_dec(string x)
{
    ll p = 1,ans = 0;
    for(int i=x.size()-1;i>=0;i--)
    {
        ans+=p*(x[i]-'0');
        p*=2;
    }
    return ans;
}
bool is_pal(string s)
{
    int low = 0,high = s.size()-1;
    while (low<=high)
    {
        if(s[low]!=s[high])
            return false;
        low++,high--;
    }
    return true;
}
void sieve()
{
    for(int i=0;i<N;i++)
        is_prime[i] = 1;
    is_prime[0] = 0,is_prime[1] = 0;
    for(int i=2;i*i<=N;i++)
    {
        if(is_prime[i])
        {
            for(int j=i*i;j<=N;j+=i)
                is_prime[j] = false;
        }
    }
}
int main()
{
    set<int>st;
    sieve();
    for(int i=0;i<N;i++)
    {
        string tmp = to_bin(i);
        if(is_prime[i] && is_pal(tmp))
            st.insert(i);
    }
    string s;
    while (cin>>s)
    {
        int tmp = to_dec(s);
        auto it = st.lower_bound(tmp);
        int ans = *it;
        string Ans = to_bin(ans);
        cout<<Ans<<"\n";
    }
    return 0;
}