#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=1e5+5;
const ll mod=1000000007;
map<string,int>mp;
int main()
{
    ll i=0,j=0,c=0;
    string s1,s2;
    cin>>s1>>s2;
    while(i<s1.size() && j<s2.size())
    {
        if(s1[i]!='L'&& s2[j]!='L')
            i++,j++,c++;
        else if(s1[i]=='L'&& s2[j]=='L')
            i++,j++,c++;
        else if(s1[i]!='L' && s2[j]=='L')
        {
            while(s1[i]!='L'&& i<s1.size())
                i++,c++;
            c++;
            j++;
            if(i<s1.size()&& s1[i]=='L')
                i++;
        }
        else if(s1[i]== 'L' && s2[j]!='L')
        {
            while(s2[j] !='L'&&j<s2.size())
                 j++,c++;
            c++;
            i++;
            if(j<s2.size() && s2[j]=='L')
                j++;
        }
    }
    while(i<s1.size())
        i++,c++;
    while(j<s2.size())
        j++,c++;
    cout<<c<<endl;
    return 0;
}
