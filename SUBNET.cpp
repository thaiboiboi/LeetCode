#include <iostream>
#include "stdio.h"
#include "string.h"
#include <sstream>

using namespace std;
string NhiPhan(unsigned int x)
{
    string s1="";
    while (x>0)
    {
        if (x%2==1)
          s1="1"+s1;
        else
          s1="0"+s1;
        x/=2;
    }
    return s1;
}
int main()
{
    struct mang
    {
      unsigned int x1,x2,x3,x4,X=0;
      char c1,c2,c3;
    };
    mang A[100],B[100];
    unsigned int m,n,Y=0,mask=0;
    string s;
    freopen("SUBNET.inp","r",stdin);
    freopen("SUBNET.out","w",stdout);
    cin>>m>>n;
    for (int i=0;i<m;++i)
    {
        mask=mask|1<<31-i;
    }

    unsigned int y1,y2,y3,y4;
    char c1,c2,c3;

    cin>>y1>>c1>>y2>>c2>>y3>>c3>>y4;
    y1<<=24;y2<<=16;y3<<=8;
    int d=0;
    Y=Y|y1;Y=Y|y2;Y=Y|y3;Y=Y|y4;
    for (int i=0;i<n;++i)
    {
        cin>>A[i].x1>>c1>>A[i].x2>>c2>>A[i].x3>>c3>>A[i].x4;
        A[i].x1<<=24;A[i].x2<<=16;A[i].x3<<=8;
        A[i].X=A[i].X|A[i].x1;
        A[i].X=A[i].X|A[i].x2;
        A[i].X=A[i].X|A[i].x3;
        A[i].X=A[i].X|A[i].x4;
        A[i].X&=mask;
        if (A[i].X==Y)
        {
            A[i].x1>>=24;
            A[i].x2>>=16;
            A[i].x3>>=8;
            B[d++]=A[i];

        }
    }
    if (d==0)
        cout<<d;
    mang t;
    for (int i=0;i<d-1;++i)
      for (int j=i+1;j<d;++j)
        if (((B[i].x3==B[j].x3)&&(B[i].x4>B[j].x4))||(B[i].x3>B[j].x3))
       {
           t=B[j];
           B[j]=B[i];
           B[i]=t;
       }
    for (int i=0;i<d;++i)
        cout<<B[i].x1<<c1<<B[i].x2<<c2<<B[i].x3<<c3<<B[i].x4<<endl;
    return 0;
}
