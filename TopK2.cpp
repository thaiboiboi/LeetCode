#include <iostream>
#include <queue>
#include "stdio.h"
using namespace std;

int main()
{
    priority_queue<int> max;
    int n,k,tam;
    freopen("TopK2.inp","r",stdin);
    freopen("TopK2.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;++i)
    {
        cin>>tam;
        max.push(tam);
    }
    while (k>0)
    {
            cout<<max.top()<<endl;
            tam=max.top();
            max.pop();
            --k;
    }
    return 0;
}
