#include <bits/stdc++.h>
using namespace std;

int numcov[5][5];
int know[5][5];
bool imposs[5][5];
int nknow;

int main() {
    for (int it = 0; it < 5; ++it) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                numcov[i][j] = 0;
            }
        }

        int nposs = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (!imposs[i][j]) {
                    ++nposs;
                    ++numcov[i][j];
                    ++numcov[i+1][j];
                    ++numcov[i][j+1];
                    ++numcov[i+1][j+1];
                }
            }
        }

        int mcov = 100;
        int mi = 0;
        int mj = 0;

        // for (int i = 0; i < 5; ++i) {
        //     for (int j = 0; j < 5; ++j) {
        //         cout << numcov[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << nposs << endl;

        if (nposs == 1) break;

        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (know[i][j]) continue;
                if (abs(2 * numcov[i][j] - nposs) < abs(2 * mcov - nposs)) {
                    mcov = numcov[i][j];
                    mi = i;
                    mj = j;
                }
            }
        }

        if (mcov == 100) break;

        cout << "? " << mi+1 << " " << mj + 1 << endl;

        int r;
        cin >> r;

        know[mi][mj] = true;

        if (r) {
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (mi == i && mj == j ||
                        mi == i+1 && mj == j ||
                        mi == i && mj == j + 1 ||
                        mi == i+1 && mj == j+1) {
                        continue;
                    }
                    imposs[i][j] = 1;
                }
            }
        } else {
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    if (mi == i && mj == j ||
                        mi == i+1 && mj == j ||
                        mi == i && mj == j + 1 ||
                        mi == i+1 && mj == j+1) {
                        imposs[i][j] = 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (!imposs[i][j]) {
                cout << "! " << i+1 << " " << j+1 << endl;
            }
        }
    }
}
