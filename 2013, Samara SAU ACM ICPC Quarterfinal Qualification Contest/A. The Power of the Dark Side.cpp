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
const int N = 1e5+5;
const int mod = 1e9+7;
int main()
{
    /*
     ll n, s;
    cin >> n >> s;
    ll arr[n + 5], cumm_sum[n + 5], need[n + 5];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cumm_sum[0] = arr[0], need[0] = arr[0] - s;
    for (int i = 1; i < n; ++i) {
        cumm_sum[i] = cumm_sum[i - 1] + arr[i];
        need[i] = cumm_sum[i] - s;
    }
    map<ll, int> cnt;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt[need[i]])
            ans++;
        if (arr[i] == s)
            ans++;
        cnt[cumm_sum[i]]++;
    }
    cout << ans << '\n';
    */

    ll n;
    cin >> n;
    ll arr[n+5][3];
    ll mxmid=-1,mxlow=-1;

    for(int i=0;i<n;i++)
    {
        for (int j = 0; j < 3; ++j)
            cin >> arr[i][j];

        sort(arr[i],arr[i]+3);
        mxmid=max(mxmid,arr[i][1]);
        mxlow=max(mxlow,arr[i][0]);
    }
    vector <int>ans;
    for (int i = 0; i < n; ++i)
    {
        if(arr[i][2]>mxmid && arr[i][1]>mxlow)
            ans.push_back(i+1);
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() <<"\n";
    for(auto i:ans)
        cout << i << " ";
    cout << "\n";


    return 0;
}