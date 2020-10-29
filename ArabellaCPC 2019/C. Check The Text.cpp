#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
const int N=55;
int main()
{
    bool lower = true;
    string word="";
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        if(i)
            word+=' ';
        word+=s;
    }
    string ans;
    int m;
    cin>>m;
    while(m--)
    {
        string s;
        cin>>s;
        if(s=="CapsLock")
        {
            lower=!lower;
        }
        else if(s=="Backspace")
        {
            if(ans.size())
                ans.pop_back();
        }
        else if(s=="Space")
        {
            ans+=' ';
        }
        else
        {
            if(lower)
                ans+=s[0];
            else
                ans+=s[0]-32;
        }
    }
    if(ans==word)
        cout<<"Correct";
    else
        cout<<"Incorrect";
    return 0;
}
