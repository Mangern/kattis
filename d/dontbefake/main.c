#include <stdio.h>

#define mxN 86401

int cnt[mxN];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        int m;
        scanf("%d", &m);

        for (int j = 0; j < m; ++j) {
            int l, r;
            scanf("%d%d", &l, &r);

            for (int k = l; k <= r; ++k)++cnt[k];
        }
    }

    int mx = 0;
    for (int i = 0; i < mxN; ++i)if (cnt[i]>mx)mx=cnt[i];
    int num=0;
    for (int i = 0; i < mxN; ++i) if (cnt[i] == mx)++num;
    printf("%d\n%d\n", mx,num);
}
