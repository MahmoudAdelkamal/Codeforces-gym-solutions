#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <vector>
#include <string>

using namespace std;
/*
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
        else{
            cout << s[idx];
            printM(idx + 1 , lastChar);
            return;
        }

    }
}
*/

int main()
{
   ios_base::sync_with_stdio(0),cin.tie(0);

   /*
   cin >> n >> s;

    memset(dp , -1, sizeof(dp));
    cout << solve(0 , 0) << '\n';
    printM(0,0);
*/
    int n;
    cin>>n;
    bool arr[200001][5];
    for (int i = 0 ; i < n; i++)
    {
        for (int x = 0; x < 5; x++)
            cin>>arr[i][x];
    }
    for (int first = 0; first < 4; first++)
    {
        for (int second = first+1; second < 5; second++)
        {
            int fcntr = 0, scntr= 0, both = 0;
            bool valid = true;
            for (int i = 0 ;i < n; i++)
            {
                if (arr[i][first] && arr[i][second])
                    both++;
                else if (arr[i][first])
                    fcntr++;
                else if (arr[i][second])
                    scntr++;
                else
                    valid = false;
            }
            if (valid)
            {

                if (min(fcntr,scntr) + both>= n/2)
                {
                    cout << "YES\n";
                    return 0;
                }
            }
        }
    }
    cout<<"NO\n";
    return 0;

    }