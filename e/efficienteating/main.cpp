#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<ll> qt(n, 0);

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;

        for (int j = 0; j < k; ++j) {
            ll t, w;
            cin >> t >> w;

            if (w > 0 && w < qt[i]) {
                continue;
            }
            qt[i] += t;
        }
    }

    cout << (min_element(begin(qt), end(qt)) - begin(qt)) << endl;
}
