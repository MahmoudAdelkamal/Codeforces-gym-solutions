#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <vector>
#include <string>

using namespace std;


int main()
{
    bool valid = 1;
    string s1,s2;
    int n;
    cin>>n;
    cin>>s1>>s2;
    for(int i=0;i<n;i++)
    {
        if(s1[i]=='1' && s2[i]=='1')
            valid = 0;
    }
    if(valid)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

}