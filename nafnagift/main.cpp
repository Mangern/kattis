#include <bits/stdc++.h>
using namespace std;

const int mxN = 1005;

int nxti[mxN][mxN];
int nxtj[mxN][mxN];
int lcs[mxN][mxN];

int main() {
    string s, t;
    cin >> s >> t;

    int n = s.length();
    int m = t.length();

    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (lcs[i+1][j] > lcs[i][j+1]) {
                lcs[i][j] = lcs[i+1][j];
                nxti[i][j] = 1;
                nxtj[i][j] = 0;
            } else {
                lcs[i][j] = lcs[i][j+1];
                nxti[i][j] = 0;
                nxtj[i][j] = 1;
            }

            if (s[i] == t[j] && lcs[i+1][j+1] + 1 > lcs[i][j]) {
                lcs[i][j] = lcs[i+1][j+1] + 1;
                nxti[i][j] = 1;
                nxtj[i][j] = 1;
            }
        }
    }

    string ret;

    int iptr = 0;
    int jptr = 0;

    while (iptr < n || jptr < m) {
        if (iptr == n) {
            ret.push_back(t[jptr++]);
            continue;
        }
        if (jptr == m) {
            ret.push_back(s[iptr++]);
            continue;
        }

        int ni = nxti[iptr][jptr];
        int nj = nxtj[iptr][jptr];

        if (ni && nj) {
            ret.push_back(s[iptr]);
            ++iptr, ++jptr;
        } else if (ni) {
            ret.push_back(s[iptr++]);
        } else {
            ret.push_back(t[jptr++]);
        }
    }

    cout << ret << endl;
}
