	#include "stdio.h"
	#include <iostream>
	#include <bits/stdc++.h>
	#define MAXN 10000001
		using namespace std;
  	bool a[MAXN];
  	long long x;
  	void songuyento()
{
    memset(a,true,sizeof(a));
    a[0]=false;
    a[1]=false;
    for (int i=2;i<MAXN;i++)
    {
        if (a[i]==true)
            for (int j=2*i;j<MAXN;j+=i)
                a[j]=false;
    }
}
int main()
{
    freopen("USNTLN.inp","r",stdin);
    freopen("USNTLN.out","w",stdout);
    songuyento();
    vector<int> prime;
    for (int i=1;i<=MAXN-1;i++)
    {
        if (a[i]==true)
            prime.push_back(i);
    }
    long long k;
    while ((cin>>x)&&(x!=0))
    {
        long long maxx=0;
	int d=0;
        for (int i=0;i<prime.size();i++)
            if(x%prime[i]==0)
                {
                    if (prime[i]>maxx)
                        maxx=prime[i];
                    d++;
                }
        if (d<2)
            cout<<-1<<endl;
        else
            cout<<maxx<<endl;
    }
    return 0;
}

