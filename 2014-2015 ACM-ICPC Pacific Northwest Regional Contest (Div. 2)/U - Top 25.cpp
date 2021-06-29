#include<iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
#define ll long long
const int N = 1e6+5;
string arr[N];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unordered_set<string>st;
        int n,prv = -1;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            if(!st.count(s))
                st.insert(s);
            else
                st.erase(s);
            if(!st.count(arr[i]))
                st.insert(arr[i]);
            else
                st.erase(arr[i]);
            if(!st.size())
            {
                cout<<i-prv<<" ";
                prv = i;
            }
        }
        cout<<"\n";
    }
    return 0;
}