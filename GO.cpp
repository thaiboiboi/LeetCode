#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n,tong=0;
int path[1000]={1};
vector<int> ke[1000];

void demduong()
{
    for (int i=0; i<n; ++i)
    {
        if ((int)ke[i].size()==0)
            tong+=path[i];
        else
            for (int j=0; j<(int)ke[i].size(); ++j)
              path[ke[i][j]]+=path[i];
    }
}

int main()
{
    freopen("GO.inp","r",stdin);
    freopen("GO.out","w",stdout);
    int x,t;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        for (int j=0; j<x; ++j)
        {
          cin>>t;
          ke[i].push_back(t);
        }
    }
    demduong();
    cout<<tong;
    return 0;
}
