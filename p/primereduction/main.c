#include <stdio.h>

typedef long long ll;

#define mxN 46500

int spf[mxN];
int primes[mxN];
int nprimes;

void pre() {
    for (ll i = 2; i < mxN; ++i) if (!spf[i]) {
        spf[i] = i;
        primes[nprimes++] = i;
        for (ll j = i * i; j < mxN; j += i) if (!spf[j]) spf[j] = i;
    }
}

int getspf(int n) {
    if (n < mxN) {
        return spf[n];
    }

    for (int i = nprimes-1; i >= 0; --i) {
        if (n % primes[i] == 0) return primes[i];
    }
    return n;
}

int main() {
    pre();

    for (;;) {
        int n;
        scanf("%d", &n);
        if (n == 4) break;

        int cnt = 1;
        while (getspf(n) != n) {
            cnt += 1;
            int y = n;
            n = 0;
            while (y > 1) {
                int p = getspf(y);
                n += p;
                y /= p;
            }
        }
        printf("%d %d\n", n, cnt);
    }
    return 0;
}
