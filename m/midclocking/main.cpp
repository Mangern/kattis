#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    scanf("%d%d", &n, &s);

    vector<int> a(n);
    for (auto &x : a) {
        scanf("%d", &x);
    }

    sort(begin(a), end(a));

    if (n == 1) {
        printf("%d\n", a[0]);
        return 0;
    }

    double ans = a[n-1] / 0.3;

    for (int n_alone = 0; n_alone <= n; ++n_alone) {
        int r = s - 2 * n_alone;
        int m = n - n_alone;

        if (r < m) break;

        if (m == 1) {
            ans = min(ans, (double)a[n-1]);
            break;
        }

        double cur = a[n-1];
        int n_two = 2 * (r - m) + 2;
        if (n_alone <= n - 1) {
            cur = max(cur, a[n-1-n_alone]/0.6);
        }
        if (n-1-n_alone-n_two >= 0) {
            cur = max(cur, a[n-1-n_alone-n_two] / 0.3);
        }
        ans = min(ans, cur);
    }

    printf("%.10f\n", ans);
}
