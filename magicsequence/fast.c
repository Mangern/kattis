#pragma GCC optimize ("Ofast")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define mxN 1000006
#define K 64

int n; 
long a, b, c, x, y, v;

int seq_[mxN];
int bseq_[mxN];
int cnt[64];

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int *seq = seq_;
    int *bseq = bseq_;
    int t;
    scanf("%d", &t);
    while (t-->0) {
        scanf("%d", &n);
        scanf("%ld%ld%ld", &a, &b, &c);
        seq[0] = a;
        for (int i = 1; i < n; ++i) {
            seq[i] = (seq[i-1] * b + a) % c;
        }

        b %= c;
        a %= c;

        scanf("%ld%ld", &x, &y);

        for (int k = 0; k < 30; k += 6) {
            int ptr = 0;
            memset(cnt, 0, sizeof cnt);

            for (int i = 0; i < n; ++i) {
                ++cnt[(seq[i]>>k)&0b111111];
            }
            for (int i = 1; i < K; ++i) {
                cnt[i] += cnt[i-1];
            }

            for (int i = n - 1; i >= 0; --i) {
                bseq[(cnt[(seq[i]>>k)&0b111111]--)-1] = seq[i];
            }
            int *tmp = seq;
            seq = bseq;
            bseq = tmp;
        }

        v = 0;
        for (int i = 0; i < n; ++i) {
            v = (v * x + seq[i]) % y;
        }
        printf("%ld\n", v);
    }
    return 0;
}

