#include <bits/stdc++.h>
using namespace std;

int main() {
    for (;;) {
        int w, h;
        if (!(cin >> w)) break;
        cin >> h;

        vector<vector<vector<int>>> occ(w, vector<vector<int>>(h, vector<int>()));

        int n;
        cin >> n;

        vector<string> name(n);
        for (int i = 0; i < n; ++i) {
            int x1, y1, x2, y2;
            cin >> name[i];
            cin >> x1 >> y1 >> x2 >> y2;
            for (int x = x1; x < x2; ++x) {
                for (int y = y1; y < y2; ++y) {
                    occ[x][y].push_back(i);
                }
            }
        }

        int unocc = 0;
        int tot = 0;
        int contest= 0;
        vector<int> alone(n, 0);
        for (int x = 0; x < w; ++x) {
            for (int y = 0; y < h; ++y) {
                ++tot;
                if (occ[x][y].empty()) {
                    ++unocc;
                } else if (occ[x][y].size() > 1) {
                    ++contest;
                } else {
                    ++alone[occ[x][y][0]];
                }
            }
        }

        cout << "Total " << tot << endl;
        cout << "Unallocated " << unocc << endl;
        cout << "Contested " << contest << endl;
        for (int i = 0; i < n; ++i) {
            cout << name[i] << " " << alone[i] << endl;
        }
        cout << endl;
    }
}
