#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;
using vi = vector<int>;

const int mxN = 105;

int n, m, s, d;
int c[mxN];

int main() {
    cin >> n >> m >> s >> d;

    for (int i = 0; i < s; ++i) {
        cin >> c[i];
    }

    vi idx(s);
    iota(begin(idx), end(idx), 0);

    sort(begin(idx), end(idx), [] (int i, int j) {
        return c[i] < c[j];
    });

    vi ans(s, 0);

    for (int i = 0; i < s; ++i) {
        int take = min(n, d - c[idx[i]]);
        ans[idx[i]] = take;
        n -= take;
    }

    if (n) {
        cout << "impossible" << endl;
        return 0;
    }

    int sm = 0;
    for (int i = 0; i < s; ++i) {
        if (ans[idx[i]] == 0) {
            sm += c[idx[i]];
        }
    }
    if (sm < m) {
        cout << "impossible" << endl;
        return 0;
    }
    for (int i = 0; i < s; ++i) {
        cout << ans[i] << " \n"[i==s-1];
    }
}
