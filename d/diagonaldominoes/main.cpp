#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    while (T-->0) {
        int n, m;
        scanf("%d%d", &m, &n);

        vector<tuple<int,int,int>> ans;

        for (int i = m + 1; i <= n; ++i) {
            if (i == 1) continue;
            for (int j = 0; j < i-1; ++j) {
                ans.emplace_back(i, 2*j+1, 2*j+2);
            }
        }
        printf("%zu\n", ans.size());
        for (auto [r, t1, t2] : ans) {
            printf("%d %d %d %d\n", r, t1, r, t2);
        }
    }
}
