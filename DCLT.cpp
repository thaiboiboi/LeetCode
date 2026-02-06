#include<bits/stdc++.h>
#include<queue>

using namespace std;

queue<int> q;
int main()
{
    long long m,d,s=0;
    freopen("DCLT.inp","r",stdin);
    freopen("DCLT.out","w",stdout);
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        q.push(x);
        s+=x;
        while (s>m)
            {
                s-=q.front();
                q.pop();
            }
        if (s==m)
            d++;
    }
    cout<<d;
    return 0;
}
