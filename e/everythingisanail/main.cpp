#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> task(n);
    for (auto & x : task) cin >> x;

    vector<int> chose = {0,1,2};

    int ans = 0;
    do {
        vector<int> p0(n,0);
        vector<int> p1(n,0);
        vector<int> s2(n,0);

        for (int i = 0; i < n; ++i) {
            if (i >0) {
                p0[i] += p0[i-1];
                p1[i] += p1[i-1];
            }
            if (task[i] == chose[0]) {
                ++p0[i];
            }
            if (task[i] == chose[1]) {
                ++p1[i];
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            if (i < n - 1)s2[i] += s2[i+1];
            if (task[i] == chose[2])++s2[i];
        }
        int cur = 0;
        int mx = 0;

        for (int i = n - 1; i >= 0; --i) {
            // do task0 upto i
            // task1 after i
            cur = max(cur, p0[i] - p1[i] + mx);
            mx = max(mx, p1[i] + (i==n-1?0:s2[i+1]));
        }
        // don't do task 0 at all
        cur = max(cur, mx);
        ans = max(ans,cur);
    } while (next_permutation(begin(chose), end(chose)));

    cout << ans << endl;
}
