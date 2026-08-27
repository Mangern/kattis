#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> ret;
    for (int k = 0; k <= n; ++k) {
        if (k * 2 + (n - k) * 4 == m) {
            ret.push_back(n - k);
        }
    }

    if (ret.size() != 1) {
        cout << "Rong talning" << endl;
    } else {
        cout << ret[0] << endl;
    }
}
