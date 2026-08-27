#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    for (;;) {
        int n;
        cin >> n;
        if (!n)break;

        vector<ll> lens;
        for (int i = 0; i < n; ++i) {
            string r;
            cin >> r;

            r.erase(r.find('.'), 1);
            lens.push_back(2*stoll(r));
        }
        sort(begin(lens), end(lens));
        ll smal = 0;
        bool pos = 0;
        for (int i = 0; i < n; ++i) {
            if (lens[i] <= smal) {
                pos = 1;
            }
            smal += lens[i];
        }
        cout << (pos?"YES":"NO") << endl;
    }
}
