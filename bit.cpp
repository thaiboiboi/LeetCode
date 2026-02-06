#include <iostream>
#include "string.h"
#include "math.h"
#include "stdio.h"
using namespace std;

string NhiPhan(int x)
{
    string s1="";
    while (x>0)
    {
        if (x%2==1)
          s1="1"+s1;
        else
          s1="0"+s1;
        x/=2;
    }
    return s1;
}
int ThapPhan(string s)
{
    int t=0;
    for (int i=s.size();i>=0;--i)
    {
        if (s[i]=='1')
            t+=pow(2.0,s.size()-i-1);
    }
    return t;
}
int main()
{
    string s;
    int n,m;

    cin>>n>>m;

    int t=0,t1=0,tam;
   //Bật bit
    for (int i=1;i<=n;++i)
    {
        cin>>tam;
        t+=pow(2.0,tam-1); //công thức BẬT BIT nè
    }
    for (int i=1;i<=m;++i)
    {
        cin>>tam;
        t1+=pow(2.0,tam-1);
    }
    //A giao B
    tam=t&t1;
    s=NhiPhan(tam);
    cout<<s<<endl;
    //A hợp B
    tam=t|t1;
    s=NhiPhan(tam);
    cout<<s<<endl;
    //A tru B
    tam=t &(~t1);
    s=NhiPhan(tam);
    cout<<s<<endl;
    return 0;
}
