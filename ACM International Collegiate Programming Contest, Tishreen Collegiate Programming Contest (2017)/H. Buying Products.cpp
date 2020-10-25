//#include <bits/stdc++.h>
#include<iostream>
#include<utility>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<cfloat>
#include<functional>
#include<string>
#include<numeric>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<chrono>
#include<cctype>
#include<iterator>
#include<bitset>
#include<locale>
#include <chrono>
#include <ctime>
#define _CRT_SECURE_NO_DEPRECATE
#define read(FILE)  freopen(FILE, "r", stdin);
#define out(FILE) freopen(FILE, "w", stdout);
#define all(x) x.begin(),x.end()
#define rep(i,m,n) for(int i=m ; i<n ; i++)
#define forr(i,m,n) for(int i=m ; i<=n ; i++)
#define enl '\n'
#define pb push_back
#define pff push_front
#define re return
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int N = 1e5 + 5;
using namespace std;
int main()
{
	IO;
	int t;
        cin >> t;
	while (t--)
	{
		vector<ll>v;
                ll arr[1005],sum=0;
		int n,k,mx=0;
                cin >> n >> k;
		while (n--)
		{
	     	    rep(i, 0, 3)
		       cin>>arr[i];
		    sort(arr,arr + 3);
		    v.pb(arr[0]);
                    v.pb(arr[1]);
		}
		sort(all(v));
		rep(i, 0, k)
		    sum += v[i];
		cout<<sum<<enl;
	}
}
