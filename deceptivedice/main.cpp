#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main() {
    int n, k;
    cin >> n >> k;

    vector<ld> opt(k+1);

    for (int i = 0; i < k; ++i) {
        ld sm = 0.0;
        for (int j = 1; j <= n; ++j) {
            ld prv = i == 0 ? 0.0 : opt[i-1];
            if (j > prv) {
                sm += j;
            } else {
                sm += prv;
            }
        }
        opt[i] = sm / (ld)n;
    }

    cout << setprecision(15) << fixed << opt[k-1] << endl;
}
