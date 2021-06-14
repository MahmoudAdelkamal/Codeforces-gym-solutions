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
set<int>st;
void primeFactors(int n)
{
    while(n%2==0)
    {
        st.insert(2);
        n/=2;
    }
    for(int i=3;i*i<=n;i+=2)
    {
        while (n%i==0)
        {
            st.insert(i);
            n/=i;
        }
    }
    if(n>1)
        st.insert(n);
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        st.clear();
        int a,b;
        cin>>a>>b;
        primeFactors(a);
        primeFactors(b);
        cout<<st.size()<<"\n";
    }
 
    return 0;
}