#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <iomanip>
#include <math.h>
#include <cmath>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#define  ll long double
using namespace std;
const int N = 2e5+5;

int col[N] , sub[N] , n;

int startNode = -1, parOfStartNode = -1;

vector< int > adj[N];

void dfs(int u , int par){

    sub[u] = 1;

    for(auto v : adj[u]){

        if(v == par)
            continue;

        dfs(v , u);

        sub[u] += sub[v];
    }
    if(sub[u] == n / 2){
        startNode = u;
        parOfStartNode = par;
    }
}
void color(int u ,int par , int parOfStartNode){
    for(auto i : adj[u]){
        if(i != parOfStartNode && i != par){
            col[i] = 1;
            color(i, u , parOfStartNode);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);

    cin >> n; int u,v;

    for(int i = 0 ; i < n - 1 ; i++){

        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1 , -1);

    if(startNode == -1){
        cout << "NO";;
        return 0;
    }
    cout << "YES\n";

    color(startNode ,-1, parOfStartNode);
    col[startNode] = 1;
    for(int i = 1; i <= n ; i++){
        cout << col[i] << " ";
    }

}