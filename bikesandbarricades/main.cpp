#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> yvals;

    for (int i = 0; i < n; ++i) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1>x2) {
            swap(x1,x2);swap(y1,y2);
        }

        if (x1 > 0 or x2 < 0) continue;
        double m = (y2 - y1) / (x2 - x1);
        double y0 = y1 - m * x1;

        if (y0 < 0) continue;
        yvals.push_back(y0);
    }

    if (yvals.empty()) {
        cout << -1.0 << endl;
    } else {
        cout << setprecision(8) << fixed << *min_element(begin(yvals),end(yvals)) << endl;
    }
}
