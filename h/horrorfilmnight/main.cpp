#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6;

bitset<mxN> l1, l2;

int main() {
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        int x;
        scanf("%d", &x);
        l1.set(x);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
        int x;
        scanf("%d", &x);
        l2.set(x);
    }

    int dp01 = 0, dp10 = 0, dp11 = 0;
    for (int i = 0; i < mxN; ++i) {
        int i1 = l1.test(i);
        int i2 = l2.test(i);

        if (i1 && i2) {
            dp11 = max(dp11 + 1, max(dp01 + 1, dp10 + 1));
        } else if (i1) {
            dp10 = max(dp11 + 1, dp01 + 1);
        } else if (i2) {
            dp01 = max(dp11 + 1, dp10 + 1);
        }
    }
    printf("%d\n",max(dp11, max(dp01, dp10)));
}
