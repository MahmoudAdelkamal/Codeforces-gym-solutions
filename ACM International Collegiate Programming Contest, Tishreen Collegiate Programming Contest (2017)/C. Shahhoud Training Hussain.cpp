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
	ll t;
	cin >> t;
	while (t--)
	{
		ll k, p, n;
		cin >> k >> p >> n;
		cout << (k - min(p, k)) * n<<endl;
	}

}
