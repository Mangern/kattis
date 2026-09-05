#include <bits/stdc++.h>
using namespace std;

int main() {
    int f;
    cin >> f;

    vector<vector<int>> files(f);
    for (int i = 0; i < f; ++i) {
        int l;
        cin >> l;
        for (int j = 0; j < l; ++j) {
            int x;
            cin >> x;
            files[i].push_back(x);
        }
    }

    int best_sz = 1;
    int best_save = 0;

    for (int sz = 1; sz <= 79; ++sz) {
        int save = 0;
        for (auto& file : files) {
            for (auto line : file) {
                int num_tabs = line / sz;
                save += line - num_tabs - line % sz;
            }
        }

        if (save > best_save) {
            best_sz = sz;
            best_save = save;
        }
    }
    cout << best_sz << endl << best_save << endl;
}
