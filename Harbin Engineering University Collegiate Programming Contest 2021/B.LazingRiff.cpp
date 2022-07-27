    #include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+5;
int main()
{
    set < char> st;
    string s;
    cin>>s;
    for(auto e:s)
        st.insert(e);
    if(st.size()>1)
        cout << 2 << endl;
    else
        cout << -1 << endl;
    return 0;
}
