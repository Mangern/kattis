#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int num = 0;

    for (int i = 0; i < n; ++i) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 > x2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        double i1 = floor(x1);
        if (i1 + 1.0 <= x2) {
            ++num;
        }
    }
    double ans = 2 * n / (double)num;
    cout << setprecision(12) << fixed << ans << endl;
}
