#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();

    vector<string> rots;
    for (int i = 0; i < n; ++i) {
        char f = s[0];
        s = s.substr(1);
        s.push_back(f);
        rots.push_back(s);
    }

    sort(begin(rots), end(rots));

    for (int i = 0; i < n; ++i) {
        int lb = 0; // first in
        int ub = n;
        for (int j = i; j >= 0; --j) {
            int lo = lb;
            int hi = ub - 1;

            int idx = i - j;
            char cur = s[j];

            // Find the first and last position in rots where rot[idx] == cur

            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (rots[mid][idx] >= cur) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }

            if (rots[lo][idx] != cur) {
                // Not found
                cout << 0 << endl;
                return 0;
            }
            lb = lo;

            // Find the last position
            hi = ub - 1;
            while (lo < hi) {
                int mid = (lo + hi + 1) / 2;
                if (rots[mid][idx] <= cur) {
                    lo = mid;
                } else {
                    hi = mid - 1;
                }
            }
            ub = lo + 1;
        }
    }

    cout << 1 << endl;
}
