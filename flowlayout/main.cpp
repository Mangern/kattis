#include <bits/stdc++.h>
using namespace std;

int main() {
    int m;
    while (cin >> m, m) {
        int mw = 0;
        int cw = 0;
        int ch = 0;
        int mh = 0;

        while (true) {
            int w, h;
            cin >> w >> h;

            if (w == -1 || cw + w > m) {
                mh += ch;
                mw = max(mw, cw);
                ch = 0;
                cw = 0;

                if (w == -1)break;
            }
            cw += w;
            ch = max(ch, h);
        }

        cout << mw << " x " << mh << endl;
    }
}
