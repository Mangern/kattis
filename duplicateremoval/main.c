#include <stdio.h>

int main() {
    for (;;) {
        int n;
        scanf("%d", &n);
        if (!n) break;
        int p = -1;
        for (int i = 0; i < n; ++i) {
            int x;
            scanf("%d", &x);
            if (x == p) continue;
            printf("%d ", x);
            p = x;
        }
        printf("$\n");
    }
}
