#include <bits/stdc++.h>
#define salma ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define RW freopen("bad-memes.in", "r", stdin);
typedef long long ll;
typedef long double ld;
#define F first
#define S second
using namespace std;
const int N =  2 * 1e5 + 5 ;
const int M = sqrt(N) + 5;
const int mod = 1e9 + 7;
const double PI = 2 * acos(0);
//int dy[]= {1,-1,0,0,1,1,-1,-1};
//int dx[]= {0,0,1,-1,1,-1,-1,1};
 
 
int main()
{
    salma;
    string s;
    cin >> s;
    int ans = -1e9;
    vector<int> mem(55, 1);
    for(int i = 1; i < s.size(); i++) 
    {
        for(int j = 0; j < i; j++)
        {
            if(s[j] < s[i])
                mem[i] = max(mem[i], mem[j] + 1);
        }
    }
    for(int i = 0; i < s.size(); i++)
    ans = max(ans,  mem[i]);
    cout << 26 - ans ;
 
    return 0;
}