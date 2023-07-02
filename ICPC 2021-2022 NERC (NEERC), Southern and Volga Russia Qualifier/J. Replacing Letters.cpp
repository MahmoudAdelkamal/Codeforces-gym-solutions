#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#define  ll long long
using namespace std;
const int N = 2e5+5;

const int MAX_N = 2e5 + 6;

int dp[MAX_N][30] , n;

string s;

int solve(int idx , int lastChar){

    if(idx == n)
        return 0;

    int &ret = dp[idx][lastChar];

    if(~ret)
        return ret;

    ret = 1e6;

    for(char c = lastChar + 'a'; c <= 'z' ; c++){
        ret = min(ret , solve(idx + 1 , c - 'a') + (c != s[idx]));
    }

    return ret;
}
void printM(int idx , int lastChar){

    if(idx == n)
        return;


    for(char c = lastChar + 'a'; c <= 'z' ; c++){

        if(solve(idx , lastChar) == solve(idx + 1 , c - 'a') + (c != s[idx])){
            cout << c;
            printM(idx + 1 , c - 'a');
            return;

        }
    }
    cout << s[idx];
    printM(idx + 1 , lastChar);
    return;
}

//ll a[N];
int main()
{
   ios_base::sync_with_stdio(0),cin.tie(0);


   cin >> n >> s;

    memset(dp , -1, sizeof(dp));
    cout << solve(0 , 0) << '\n';
    printM(0,0);
    return 0;
}