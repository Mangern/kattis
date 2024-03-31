#include <bits/stdc++.h>
using namespace std;

int n, k, l;

int main() {
    cin >> n >> k >> l;

    l *= 2;

    vector<pair<float, int>> rgt;

    vector<float> ans(k, 0.0);

    for (int i = 0; i < n; ++i) {
        float d;
        int b;
        char c;
        cin >> d >> b >> c;

        d *= 2.0;

        if (c == 'L') {
            float p = d;
            for (int j = rgt.size() - 1; j >= 0; --j) {
                float pos = rgt[j].first;
                int col = rgt[j].second;

                float midpoint = (pos + d) / 2.0;

                ans[b] += p - midpoint;
                b = (b + col)%k;
                p = midpoint;

                if (j == 0) {
                    ans[b] += p;
                }
            }
        } else {
            ans[b] += (float)l - d;
            rgt.push_back({d, b});
        }
    }

    for (auto f : ans) {
        cout << f << " ";
        f /= 2.0;
        cout << setprecision(1) << fixed << f << endl;
    }

    return 0;
}
