#include <bits/stdc++.h>
using namespace std;

const int mxN = 20;

int n, m;
int num[mxN];
int has[101];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;

        for (int j = 0; j < k; ++j) {
            int t;
            cin >> t, --t;
            has[i] |= (1<<t);
        }
    }
    int sall = accumulate(num, num+n, 0);
    int minst = sall;
    for (int mask = 0; mask < (1<<n); ++mask) {
        bool succ = 1;
        int res = 0;

        for (int i = 0; i < m; ++i) {
            if (!(mask&has[i])) {
                succ = false;
                break;
            }
            res |= (mask&has[i]);
        }
        if (!succ || res != mask) continue;

        int sm = 0;
        int x = mask;
        while (x) {
            int l = (x&(-x));
            sm += num[31-__builtin_clz(l)];
            x -= l;
        }
        minst = min(minst, sm);
    }

    cout << sall - minst << endl;
}
