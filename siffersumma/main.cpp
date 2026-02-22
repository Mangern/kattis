#include <bits/stdc++.h>
using namespace std;

const int mxN = 21;

int n;
string s;

int smallest_dp[21][9 * mxN][2];
int smallest_choice[21][9 * mxN][2];

// Find the smallest integer of a given length and digit sum
bool find_smallest(int len, int dsum, bool leading_zero) {
    int &r = smallest_dp[len][dsum][leading_zero];
    int &c = smallest_choice[len][dsum][leading_zero];
    if (r != -1) return r;
    if (dsum < 0) return r = false;

    if (len == 1) {
        if (dsum == 0) {
            c = 0;
            return r = leading_zero;
        }
        c = dsum;
        return r = dsum <= 9;
    }

    if (dsum == 0 && !leading_zero) return r = false;

    int start = 0;
    if (!leading_zero) start = 1;
    for (int d = start; d <= 9; ++d) {
        if (find_smallest(len - 1, dsum - d, true)) {
            c = d;
            return r = true;
        }
    }
    return r = false;
}

string reconstruct_smallest(int len, int dsum, bool lz) {
    string res;
    while (len) {
        int dig = smallest_choice[len][dsum][lz];
        res.push_back('0' + dig);
        dsum -= dig;
        --len;
        lz=1;
    }
    return res;
}

int main() {

    {
        for (int i = 0; i < mxN; ++i) {
            for (int j = 0; j < 9 * mxN; ++j) {
                smallest_dp[i][j][0] = -1;
                smallest_dp[i][j][1] = -1;
            }
        }
    }

    cin >> s;
    n = s.length();

    int dsum = s.back() - '0';

    for (int i = n - 2; i >= 0; --i) {
        int start = s[i]-'0';

        // can we increase?
        for (int d = start + 1; d <= 9; ++d) {
            int remdsum = dsum - (d - start);
            int len = n - i - 1;
            bool lz = 1;
            if (find_smallest(len, remdsum, lz)) {
                string res;

                for (int j = 0; j < i; ++j) {
                    res.push_back(s[j]);
                }
                res.push_back('0' + d);

                res += reconstruct_smallest(len, remdsum, lz);

                cout << res << endl;
                return 0;
            }
        }

        dsum += start;
    }

    find_smallest(n + 1, dsum, false);

    cout << reconstruct_smallest(n + 1, dsum, false) << endl;
}
