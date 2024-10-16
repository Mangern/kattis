#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
using namespace std;

const int mxN = 46500;

vector<int> primes;
int spf[mxN];

void pre() {
    for (long long i = 2; i < mxN; ++i) if (!spf[i]) {
        spf[i] = i;
        primes.push_back(i);
        for (long long j = i * i; j < mxN; j += i) {
            if (!spf[j])spf[j] = i;
        }
    }
}

int main() {
    pre();

    int n;
    while (scanf("%d", &n) != EOF) {
        if (n < 0) {
            n = -n;
            printf("-1 ");
        }
        vector<int> ps;
        bool done = 0;
        while (n > primes.back()) {
            int i;
            for (i = primes.size() - 1; i >= 0; --i) {
                if (n % primes[i] == 0) {
                    ps.push_back(primes[i]);
                    n /= primes[i];
                    break;
                }
            }
            if (i < 0) {
                done = 1;
                ps.push_back(n);
                break;
            }
        }

        while (!done && n > 1) {
            ps.push_back(spf[n]);
            n /= spf[n];
        }

        sort(begin(ps), end(ps));

        for (int i = 0; i < ps.size(); ) {
            int j;
            for (j = i; j < ps.size() && ps[j] == ps[i]; ++j);
            printf("%d", ps[i]);
            if (j - i > 1) {
                printf("^%d", j - i);
            }
            putchar(' ');
            i = j;
        }
        printf("\n");
    }
}
