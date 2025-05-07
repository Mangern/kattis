#include<stdio.h>
#include<string.h>
#define N 1000006
#define S scanf
#define F f[i]
#define G for
int*f,*o,*h,n,i,t,k,d[N],e[N],g[64];long a,b,c,v;int main(){f=d;o=e;S("%d",&t);G(;t--;){S("%d%ld%ld%ld",&n,&a,&b,&c);f[0]=a;G(i=1;i<n;++i){F=(f[i-1]*b+a)%c;}b%=c;a%=c;S("%ld%ld",&a,&b);G(k=0;k<30;k+=6){memset(g,0,256);G(i=0;i<n;++i){++g[F>>k&63];}G(i=1;i<64;++i){g[i]+=g[i-1];}G(i=n-1;i>=0;--i){o[g[F>>k&63]---1]=F;}h=f;f=o;o=h;}v=0;G(i=0;i<n;++i){v=(v*a+F)%b;}printf("%ld\n",v);}}
