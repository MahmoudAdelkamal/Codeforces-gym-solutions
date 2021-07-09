#include<iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <bitset>
#define ll long long
using namespace std;
const int N = 1e5+5;
const int mod = 1e9+7;
int arr[3][2];
bool solve(int x,int y,int z)
{
    vector<pair<int,int>>v;
    v.push_back({arr[0][x],arr[0][!x]});
    v.push_back({arr[1][y],arr[1][!y]});
    v.push_back({arr[2][z],arr[2][!z]});
    sort(v.rbegin(),v.rend());
    return (v[0].first==(v[1].first+v[2].first) && v[0].first==(v[0].second+v[1].second) && v[1].second==v[2].second);
}
int main()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
            cin>>arr[i][j];
    }
    bool valid = 0;
    for(int i=0;i<(1<<3);i++)
    {
        bitset<3>b = i;
        if(solve(b[0],b[1],b[2]))
            valid = 1;
    }
    if(valid)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}