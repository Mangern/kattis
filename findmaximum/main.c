#include <stdio.h>
int main() { int a, b, c; scanf("%d%d%d", &a,&b,&c); int mx = a > b ? a : b; mx = mx > c ? mx : c; printf("%d\n", mx); }
