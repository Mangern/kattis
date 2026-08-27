#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define mxN 55

int n;

long A[mxN][mxN];

long B[mxN][mxN];
long C[mxN][mxN];

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%ld", &A[i][j]);
        }
    }

    bool good = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((A[i][j]&1)!=(A[j][i]&1)) {
                printf("-1\n");
                return 0;
            }

            if (labs(A[i][j]) != labs(A[j][i])) {
                good = 0;
            }
        }
    }

    if (good) {
        printf("1\n");
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%ld%c", A[i][j], " \n"[j==n-1]);
            }
        }
        return 0;
    }

    printf("2\n");
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (i == j) {
                B[i][j] = A[i][j];
                continue;
            }

            long x1 = A[i][j] - A[j][i];
            x1 /= 2;
            B[i][j] = x1;
            B[j][i] = -x1;
        }
    }

    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        printf("%ld%c", B[i][j], " \n"[j==n-1]);
    }

    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        printf("%ld%c", A[i][j] - B[i][j], " \n"[j==n-1]);
    }
}
