#include <iostream>
#include <cassert>

using namespace std;

int main() {
    bool fll = 0;
    while (true) {
        int n;
        cin >> n;
        if (!n)break;

        if (fll) {
            cout << endl;
        } else fll = 1;

        int cnt1 = 0;
        int cnt2 = 0;
        int M = 0;
        int cmov = 0;
        int cl = 0;
        for (int i = 0; i < n; ++i) {
            string cmd;
            int m;
            cin >> cmd >> m;

            M += m;

            if (cmd == "DROP") {
                cout << "DROP 2 " << m << endl;
                ++cl;
                cnt2 += m;
            } else {
                if (cnt1) {
                    int take = min(m, cnt1);
                    cout << "TAKE 1 " << take << endl;
                    ++cl;
                    cnt1 -= take;
                    m -= take;
                }
                if (m) {
                    assert(cnt2 && !cnt1);
                    cout << "MOVE 2->1 " << cnt2 << endl;
                    ++cl;
                    cmov += cnt2;

                    cnt1 = cnt2;
                    cnt2 = 0;

                    cout << "TAKE 1 " << m << endl;
                    ++cl;

                    cnt1 -= m;
                }
            }
        }

        assert(cmov <= 6 * M);
        assert(cl <= 6 * n);
    }
}
