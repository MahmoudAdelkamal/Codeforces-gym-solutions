#include <bits/stdc++.h>
#define yala ios::sync_with_stdio(0); cin.tie(0); ios_base::sync_with_stdio(0);
#define RW freopen("input.txt","mirror",stdin), freopen("output.txt","w",stdout);
#define ll long long
#define ld long double
using namespace std;
const int N = 2e5 + 9;
const int MOD = 1e9;
const ll INF = 1e18;
const double pi = 3.1415926536;
const int mod = 1e9 + 7;
typedef complex<ll>point;
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};
int main() {
    yala;
    map<string, int> pos;
    pos["C"] = 1, pos["C#"] = 2, pos["D"] = 3, pos["D#"] = 4, pos["E"] = 5, pos["F"] = 6;
    pos["F#"] = 7, pos["G"] = 8, pos["G#"] = 9, pos["A"] = 10, pos["A#"] = 11, pos["B"] = 12;
    int t;
    cin >> t;
    while (t--) {
        string n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        int dist1 = pos[n2] - pos[n1], dist2 = pos[n3] - pos[n2];
        if (dist1 < 0)
            dist1 = pos[n2] + 12 - pos[n1];
        if (dist2 < 0)
            dist2 = pos[n3] + 12 - pos[n2];
        if (dist1 == 3 && dist2 == 4)
            cout << "Minor triad\n";
        else if (dist1 == 4 && dist2 == 3)
            cout << "Major triad\n";
        else
            cout << "Dissonance\n";
    }
    return 0;
}