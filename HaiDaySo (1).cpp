#include <iostream>
#include <queue>
#include "stdio.h"
using namespace std;
int A[20001];
int main()
{   priority_queue< int,vector<int>,greater<int> > min;
    freopen("HaiDaySo.inp","r",stdin);
    freopen("HaiDaySo.out","w",stdout);
    int n,m,k,t;
    cin>>m>>n>>k;
    for (int i=1;i<=m;++i)
        cin>>A[i];
    for (int i=1;i<=n;++i)
    {
        cin>>t;
        for (int j=1;j<=m;++j)
            min.push(t+A[i]);
    }
    for (int i=1;i<=k;++i)
    {
        cout<<min.top()<<endl;
        min.pop();
    }
    return 0;
}
