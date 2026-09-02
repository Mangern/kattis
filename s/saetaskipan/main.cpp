#include <bits/stdc++.h>
using namespace std;

int main() {
    array<int,3> cnt = {0};
    cin >> cnt[0];
    cin >> cnt[1];
    cin >> cnt[2];
    int n = cnt[0] + cnt[1] + cnt[2];
    string kind = "MFN";
    string ans;

    for (int i = 0; i < n; ++i) {
        int mxi = -1;

        for (int j = 0; j < 3; ++j) {
            if (ans.size() && ans.back() == kind[j]) continue;
            if (!cnt[j]) continue;
            if (mxi == -1 || cnt[j] > cnt[mxi]) mxi = j;
        }
        if (mxi == -1) {
            cout << "O nei!" << endl;
            return 0;
        }
        ans.push_back(kind[mxi]);
        --cnt[mxi];
    }
    cout << ans << endl;
}
