#define _USE_MATH_DEFINES
#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
         int a,b,c;
         cin>>a>>b>>c;
         if(a<b)
         {
             if(a<c)
                cout<<"First"<<endl;
             else
                cout<<"Third"<<endl;
         }
         else
         {
            if(b<c)
                cout<<"Second"<<endl;
            else
                cout << "Third" <<endl;
         }
    }
  return 0;
}
