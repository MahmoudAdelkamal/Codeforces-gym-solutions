#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+5;
int n;
char mat[N][N],tmp[N][N];
string s;
char shiftLeft(char ch)
{
    if(ch=='.')
        return '.';
    if(ch=='^')
        return '<';
    if(ch=='<')
        return 'v';
    if(ch=='v')
        return '>';
    return '^';
}
char shiftRight(char ch)
{
    if(ch=='.')
        return '.';
    if(ch=='^')
        return '>';
    if(ch=='<')
        return '^';
    if(ch=='v')
        return '<';
    return 'v';
}
void shiftMatrixLeft()
{
    int col=n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            tmp[i][j]=shiftLeft(mat[j][col]);
        col--;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            mat[i][j]=tmp[i][j];
    }
}
void shiftMatrixRight()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            tmp[i][j]=shiftRight(mat[n-j+1][i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            mat[i][j]=tmp[i][j];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    cin>>n>>s;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cin>>mat[i][j];
    }
    int r = 0,l = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='L')
            l++;
        else
            r++;
    }
    int diff=abs(l-r)%4;
    if(l>r)
    {
        for(int i=0;i<diff;i++)
            shiftMatrixLeft();
    }
    else
    {
        for(int i=0;i<diff;i++)
            shiftMatrixRight();
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<mat[i][j];
        cout<<endl;
    }
    return 0;
}
