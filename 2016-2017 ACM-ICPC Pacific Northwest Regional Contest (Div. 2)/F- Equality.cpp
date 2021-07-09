#include<iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 1e5+5;
const int mod = 1e9+7;
int main()
{
    char sign,operation;
    int op1,op2,res;
    cin>>op1>>sign>>op2>>operation>>res;
    if(op1+op2==res)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}