#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> h(n), s(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i] >> s[i];
    }
    int cur = 0;

    for (int i = 1; i < n; ++i) {
        bool fl=1;
        while (h[i] > 0 && h[i-1] > 0) {
            if (fl) {
                h[i] -= s[i-1];
            } else {
                h[i-1] -= s[i];
            }
            fl = !fl;
        }

        if (h[i] <= 0) {
            h[i] = h[i-1];
            s[i] = s[i-1];
        } else {
            cur = i;
        }
    }
    cout << cur+1 << endl;
}
