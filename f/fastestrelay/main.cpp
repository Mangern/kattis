#include <bits/stdc++.h>
using namespace std;

using tup = array<int, 4>;

int main() {
    int n;
    cin >> n;

    vector<tup> a(n);
    for (auto &ar : a) {
        cin >> ar[0] >> ar[1] >> ar[2] >> ar[3];
    }

    vector<int> col = {0, 1, 2, 3};

    int ans = 1e7;
    do {
        vector<bool> taken(n, 0);
        vector<int> idx(n, 0);
        iota(begin(idx), end(idx), 0);
        int cur = 0;
        for (int c : col) {
            sort(begin(idx), end(idx), [&](auto i, auto j) {
                return a[i][c] < a[j][c];
            });
            int take;
            for (int i : idx) if (!taken[i]) {
                take = i;
                break;
            }
            taken[take] = 1;
            cur += a[take][c];
        }
        ans = min(ans, cur);
    } while (next_permutation(begin(col), end(col)));
    cout << ans << endl;
}
