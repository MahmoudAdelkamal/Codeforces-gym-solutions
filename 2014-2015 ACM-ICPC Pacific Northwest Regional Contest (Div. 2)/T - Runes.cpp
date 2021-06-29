#include<iostream>
#include <string>
#define ll long long
#define TEKA ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
char sign;
int vis[20];
int id;
ll op(ll x,ll y)
{
    if     (sign=='*')return x*y;
    else if(sign=='-')return x-y;
    else return              x+y;
}
 
bool trans(string num1,string num2,string num3,int num)
{
    ll x=0,y=0,z=0;
    if(num1.size()>1 && !num && (num1[0]=='?' || num1.size()>1 && num1[0]=='-' && num1[1]=='?'))
        return 0;
    if(num2.size()>1 && !num && (num2[0]=='?' || num2.size()>1 && num2[0]=='-' && num2[1]=='?'))
        return 0;
    if(num3.size()>1 && !num && (num3[0]=='?' || num3.size()>1 && num3[0]=='-' && num3[1]=='?'))
        return 0;
    for(int i=0; i<num1.size(); i++)
    {
        if(num1[i]=='?')num1[i]= num+'0';
    }
    for(int i=0; i<num2.size(); i++)
    {
        if(num2[i]=='?')num2[i]= num+'0';
    }
    for(int i=0; i<num3.size(); i++)
    {
        if(num3[i]=='?')num3[i]= num+'0';
    }
    return op(atoll(num1.c_str()), atoll(num2.c_str())) == atoll(num3.c_str());
}
int main()
{
    TEKA
    int t;
    cin>>t;
    string s,num1,num2,ans,tmp;
    while(t--)
    {
        id++;
        num1=num2=ans="",tmp="";
        cin>>s;
        int i=1;
        for( i=0; i<s.size(); i++)
        {
            if(i&&(s[i]=='-'||s[i]=='*'||s[i]=='+')){num1+=tmp;
                break;}
            tmp+=s[i];
        }
        sign =s[i];
        i++;
        while(s[i]!='=')
        {
            num2+=s[i];
            i++;
        }
        i++;
        for(; i<s.size(); i++)
        {
            ans+=s[i];
        }
        for(int i=0;i<num1.size();i++)
        {
            if(num1[i]>='0' && num1[i]<='9')
                vis[num1[i]-'0']= id;
        }
 
        for(int i=0;i<num2.size();i++)
        {
            if(num2[i]>='0' && num2[i]<='9')
                vis[num2[i]-'0']= id;
        }
 
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]>='0' && ans[i]<='9')
                vis[ans[i]-'0']= id;
        }
        int res=1000000;
        for(int i=0; i<=9; i++)
        {
            if(vis[i]==id)
                continue;
            if(trans(num1,num2,ans,i))res=min(res,i);
        }
        if(res ==1000000)cout<<-1<<"\n";
 
        else cout<<res<<"\n";
        //cout<<num1<<" "<<num2<<" "<<ans<<" "<<sign<<" "<<"\n";
    }
    return 0;
}