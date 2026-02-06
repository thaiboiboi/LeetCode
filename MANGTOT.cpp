#include <bits/stdc++.h>
using namespace std;
int n;
bool bad(vector<int> v)
{
    int s=0;
    for (int i:v)
    s+=i;
    if (s%2)
    return 0;
    bitset<200005> b;
    b[0]=1;
    for (int i:v)
    b|=(b<<i);
    return b[s/2];
}
int main()
{
	freopen("MANGTOT.INP","r",stdin);
freopen("MANGTOT.OUT","w",stdout);    
scanf("%d",&n);
    vector<int> v(n);
    for (int i=0;i<n;i++)
    scanf("%d",&v[i]);
    if (bad(v))
    {
        pair<int,int> mn(20,0);
        for (int i=0;i<n;i++)
        mn=min(mn,make_pair(__builtin_ctz(v[i]),i+1));
        printf("1\n%d",mn.second);
    }
    else
    printf("0");
}
