#include <bits/stdc++.h>

using namespace std;

#define MAXX 10000010

bitset<MAXX+1> prime;
vector<int> A;

void SNT()
{
	int k=sqrt(MAXX);
	for(int i=2;i<=k;++i)
	{
		if(!prime.test(i))
		{
			for(int j=i*i;j<=MAXX; j+=i)
				prime.set(j,1);
		}
	}
	for(int i=2;i<=MAXX;++i)
	{
		if(!prime.test(i))
			A.push_back(i);
	}
}

bool DSNT(int so)
{
	if (so<2) return false;
	return !prime.test(so);
}

int main()
{
    freopen("543.inp","r",stdin);
    freopen("543.out","w",stdout);
	SNT();
	int so;
	while(cin>>so)
	{
		if(!so)
			break;
		if(so<4)
		{
			continue;
		}
		vector<int>::iterator it;
		bool found = false;
		int sq=sqrt(so);
		for(it=A.begin();(it!=A.end()&&*it<=so);++it)
		{
			int p=*it;
			if(DSNT(so-p))
			{
				printf("%d = %d + %d\n",so,p,(so-p));
				found=true;
				break;
			}
		}
		if(!found)
			printf("Goldbach's conjecture is wrong.\n");
	}
	return 0;
}
