#include <iostream>
#include <stack>
#include "string.h"
#include <bits/stdc++.h>

using namespace std;
char Vt(char x, char A[100],int m)
{
    for (int i=0;i<m;++i)
      if (x==A[i])
       return i;
}
int main()
{   char A[100];
    stack<int> s;
    int n,m,top;
    char tam;
    bool d;
    freopen("SCXH.inp","r",stdin);
    freopen("SCXH.out","w",stdout);
    cin>>n>>m;
    for (int i=0;i<n;++i)
            cin>>A[i];
    string s1;
    getline(cin,s1);
    for (int i=0;i<m;++i)
    {   d=true;
        top=0;
        getline(cin,s1);
        for (int j=0;j<s1.size();++j)
        if (s1[j]!=' ')
        {
        tam=Vt(s1[j],A,n);
        if (tam<top)
        {
            if ((s.empty()==true) || (tam!=s.top()))
            {
                cout<<"N"<<endl;
                d=false;
                break;
            }
            else
            if (tam==s.top())
                s.pop();
        }
        else
        {
            for (int k=top;k<tam;++k)
               s.push(k);
            top=tam+1;
        }
        }
        if (d==true)
            cout<<"Y"<<endl;
    }
    return 0;
}
