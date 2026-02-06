#include <iostream>
#include "string.h"
#include "stack"
#include "stdio.h"

using namespace std;
bool Ktra(string s)
{
    stack<char> s1;
    for (int i=0;i<s.size();++i)
    {
        if ((s[i]=='[')||(s[i]=='(')||(s[i]=='{'))
            {
                s1.push(s[i]);
                continue;
            }
        else
          if (((s1.top()=='[')&&(s[i]==']')) || ((s1.top()=='{')&&(s[i]=='}')) || ((s1.top()=='(')&&(s[i]==')')))
            {
                s1.pop();
                continue;
            }
        return false;
    }
    if (!s1.empty())
       return false;
    else
        return true;
}
int main()
{
    string s;
    int n;
    freopen("DayNgoac.inp","r",stdin);
    freopen("DayNgoac.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;++i)
    {
       cin>>s;
       if (Ktra(s)==true)
        cout<<"TRUE"<<endl;
       else
        cout<<"FALSE"<<endl;
    }
    return 0;
}
