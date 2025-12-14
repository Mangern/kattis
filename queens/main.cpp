#include <bits/stdc++.h>
using namespace std;
using ii = array<int, 2>;

int main() {
    int n;
    cin >> n;

    vector<ii> loc(n);
    for (auto &[x, y] : loc) cin >> x >> y;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            auto [x1, y1] = loc[i];
            auto [x2, y2] = loc[j];

            if (x1 == x2 || y1 == y2 || x1+y1==x2+y2 || x1-y1 == x2-y2) {
                cout << "INCORRECT" << endl;
                return 0;
            }
        }
    }
    cout << "CORRECT" << endl;
}
