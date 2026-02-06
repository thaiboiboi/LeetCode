#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n,m;
struct ii
{
   int first,second;
};
ii A[1001];
int tg,tang[1001];
int main()
{
    int x,y,i;
    freopen("THANGMAY.inp","r",stdin);
    freopen("THANGMAY.out","w",stdout);
    cin>>n>>m;
    for (i=1;i<=m;++i){
        cin>>x>>y;
        A[i].first=x;
        A[i].second=y;
        tang[i]=A[i].second-A[i].first;
	}
	if (A[1].second==n)
    {
        cout<<tang[1]*5;
        return 0;
    }
	int min=(n-1)*5;
	tg=tang[1];
	int dd,d1,d2;
	i=1;
	d1=A[1].second;
	while (i<m)
	{
    min*=20;
    d2=d1;
     for (int j=i+1;j<=m;++j)
     if (d1==A[j].first)
               {
                if (tg+tang[j]-(tg%tang[j])+tang[j]<min)
                    {
                    min=tg+tang[j]-(tg%tang[j])+tang[j];
                    dd=j;
                    d2=A[j].first;
                    }
    }
    else
        if (d1==A[j].second)
                if (tg+tang[j]-(tg%tang[j])<min)
                    {
                    min=tg+tang[j]-(tg%tang[j]);
                    dd=j;
                    d2=A[j].second;
                    }
     tg=min;
     i=dd;
     d1=d2;
	}
	cout<<tg*5;
    return 0;
}
