#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    vector<string> fmt = {
        "NNN",
        "NNY",
        "NYN",
        "NYY",
        "YNN",
        "YNY",
        "YYN",
        "YYY",
    };
    while (T-->0) {
        int n;
        cin >> n;

        // outcome[i][mask]: 
        //     What will be the outcome if the state is mask when voter i enters the room?
        vector<vector<int>> outcome(n, vector<int>(8));

        vector<vector<int>> prefs(n, vector<int>(8));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 8; ++j) {
                int x;
                cin >> x, --x;
                prefs[i][j] = x;
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int mask = 0; mask < 8; ++mask) {
                int best = -1;
                for (int mov = 0; mov < 3; ++mov) {
                    int nmask = mask ^ (1 << mov);

                    int noutcome = nmask;
                    if (i + 1 < n) {
                        noutcome = outcome[i+1][nmask];
                    }
                    if (best == -1 || prefs[i][noutcome] < prefs[i][best]) {
                        best = noutcome;
                    }
                }
                outcome[i][mask] = best;
            }
        }

        cout << fmt[outcome[0][0]] << endl;
    }
}
