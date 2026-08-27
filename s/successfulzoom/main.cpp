#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)cin >> x;

    for (int k = 1; k <= n / 2; ++k) {
        int prv = -1;
        for (int q = 1; q*k - 1 < n; ++q) {
            if (a[q*k-1] > prv) {
                prv = a[q*k-1];
            } else {
                prv = -69;
                break;
            }
        }

        if (prv != -69) {
            cout << k << endl;
            return 0;
        }
    }

    cout << "ABORT!" << endl;
}
