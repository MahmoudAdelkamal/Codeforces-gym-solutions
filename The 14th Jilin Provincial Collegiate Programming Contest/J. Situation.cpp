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
int t,x,dots = 0;
map<pair<vector<vector<char>>,int>,int>dp;
vector<vector<char>>vec(3,vector<char>(3));
int Result(vector<vector<char>>v)
{
    int ans = 0;
    // check rows
    if(v[0][0]==v[1][0] && v[1][0]==v[2][0])
        ans+=(v[0][0]=='O')-(v[0][0]=='X');
    if(v[0][1]==v[1][1] && v[1][1]==v[2][1])
        ans+=(v[0][1]=='O')-(v[0][1]=='X');
    if(v[0][2]==v[1][2] && v[1][2]==v[2][2])
        ans+=(v[0][2]=='O')-(v[0][2]=='X');
 
 
    // check columns
    if(v[0][0]==v[0][1] && v[0][1]==v[0][2])
        ans+=(v[0][0]=='O')-(v[0][0]=='X');
    if(v[1][0]==v[1][1] && v[1][1]==v[1][2])
        ans+=(v[1][0]=='O')-(v[1][0]=='X');
    if(v[2][0]==v[2][1] && v[2][1]==v[2][2])
        ans+=(v[2][0]=='O')-(v[2][0]=='X');
 
 
    //check diagonals
    if(v[0][0]==v[1][1] && v[1][1]==v[2][2])
        ans+=(v[0][0]=='O')-(v[0][0]=='X');
    if(v[0][2]==v[1][1] && v[1][1]==v[2][0])
        ans+=(v[0][2]=='O')-(v[0][2]=='X');
    return ans;
}
int solve(vector<vector<char>>v,int turn,int rem)
{
    if(rem==0)
        return Result(v);
    if(dp.count({v,turn}))
        return dp[{v,turn}];
    int ans;
    if(turn) // Alice turn
        ans = INT_MIN;
    else  // bob turn
        ans = INT_MAX;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(v[i][j]!='.')
                continue;
            if(turn)
            {
                v[i][j] = 'O';
                ans = max(ans,solve(v,turn^1,rem-1));
            }
            else
            {
                v[i][j] = 'X';
                ans = min(ans, solve(v,turn^1,rem-1));
            }
            v[i][j] = '.';
        }
    }
    return dp[{v,turn}] = ans;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        dots = 0;
        cin>>x;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin>>vec[i][j];
                if(vec[i][j]=='.')
                    dots++;
            }
        }
        cout<<solve(vec,x,dots)<<'\n';
    }
    return 0;
}