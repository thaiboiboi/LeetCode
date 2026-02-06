#include <iostream>
#include "string.h"
#include <stack>
#include <bits/stdc++.h>

using namespace  std;

int main()
{
    stack<string> s;
    char t;
    freopen("T2H.inp","r",stdin);
    freopen("T2H.out","w",stdout);
    while (cin>>t)
    {
        if (t=='n')
            s.push("min");
        if (t=='s')
            s.push("abs");
        if (t=='x')
            s.push("max");
        if (t==')')
        {
            cout<<" "<<s.top();
            s.pop();
        }
        if ((t!='a') && (t!='b') && (t!='s') && (t!='m') && (t!='i') && (t!='n') && (t!='x') && (t!='(') && (t!=')') && (t!=','))
            cout<<t;
        if (t==',')
            cout<<" ";
    }
    return 0;
}
