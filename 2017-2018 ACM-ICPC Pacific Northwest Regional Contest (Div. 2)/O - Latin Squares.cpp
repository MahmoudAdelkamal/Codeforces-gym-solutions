#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const int N = 1e7+5;
int n,a[50][50];
int main()
{
    while(cin>>n)
    {
        set<int>r[50],col[50];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                char c;
                cin>>c;
                if(c>='0' && c<='9')
                    a[i][j] = c-'0';
                else
                    a[i][j] = c-'A'+10;
                r[i].insert(a[i][j]);
                col[j].insert(a[i][j]);
            }
        }
        bool valid = 1;
        for(int i=0;i<n;i++)
        {
            if(r[i].size()!=n)
                valid = 0;
            if(col[i].size()!=n)
                valid = 0;
        }
        if(!valid)
        {
            cout<<"No"<<endl;
            continue;
        }
        bool valid2 = 1;
        for(int i=1;i<n;i++)
        {
            // row
            if(a[0][i]<=a[0][i-1])
                valid2 = 0;
            // col
            if(a[i][0]<=a[i-1][0])
                valid2 = 0;
        }
        if(valid2)
            cout<<"Reduced"<<endl;
        else
            cout<<"Not Reduced"<<endl;
    }
    return 0;
}
