#include <bits/stdc++.h>

using namespace std;
int pisano[]={60, 300, 1500, 15000};
int mod[]={10, 100, 1000, 10000};
int t;
int main()
{
	freopen("10689.inp","r",stdin);
	freopen("10689.out","w",stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    scanf("%d",&t);
    while(t--){
        int a,b,n,m;
        scanf("%d %d %d %d",&a,&b,&n,&m);
        m--;
        int ar1=a%mod[m],  ar2=b%mod[m];
        int ar=(ar1+ar2)% mod[m];
        for(int i=2;i<=n%pisano[m];++i){
            ar=(ar1+ar2)% mod[m];
            ar2=ar1;
            ar1=ar;
        }
        printf("%d\n",ar);
    }
    return 0;
}
