#pragma GCC target("popcnt", "avx2")
#include <bits/stdc++.h>
using namespace std;

#define all(v) begin(v), end(v)
const int mxN = 3e5+5;

bool check(const vector<int>& row1, const vector<int>& row2, int w) {
    int s1 = 0;
    int s2 = 0;
    int i1 = 0;
    int i2 = 0;
    while (i1 < row1.size() || i2 < row2.size()) {
        if (i1 == row1.size()) {
            s2 += row2[i2++];
            continue;
        }
        if (i2 == row2.size()) {
            s1 += row1[i1++];
            continue;
        }

        if (s1 <= s2) {
            s1 += row1[i1++];
        } else {
            s2 += row2[i2++];
        }

        if (s1 == s2 && s1 != w) return false;
    }
    return s1 == w && s2 == w;
}

int main() {
    int n, w;
    cin >> n >> w;

    vector<int> bricks(n);
    for (auto &b : bricks) cin >> b;

    sort(all(bricks));
    bricks.erase(unique(all(bricks)), end(bricks));

    vector<vector<int>> valid_shift(w + 1);
    for (int b : bricks) {
        if (b == w) {
            // Trivial case
            cout << "possible" << endl;
            cout << 1 << endl;
            cout << b << endl;
            cout << 1 << endl;
            cout << b << endl;
            return 0;
        }
        for (int k = 1; k * b <= w; ++k) {
            valid_shift[k * b].push_back(b);
        }
    }

    bitset<mxN> sols, delta;
    for (int i = w + 1; i < mxN; ++i)sols.set(i);
    sols.set(0);
    vector<int> cf(w+1, -1);
    for (int b = 1; b <= w; ++b) {
        if (valid_shift[b].empty()) continue;
        delta = (sols << b) & ~sols;
        sols |= delta;
        while (delta.count()) {
            int bit = delta._Find_first();
            cf[bit] = b;
            delta.reset(bit);
        }
        if (cf[w] != -1) break;
    }

    if (cf[w] == -1) {
        cout << "impossible" << endl;
        return 0;
    }
    int bx = -1, by = -1;
    int initial_shift = 0;

    for (int b = 1; b < w && bx == -1; ++b) {
        if (valid_shift[b].empty()) continue;

        if (cf[w - b] != -1) {
            // choose bx from valid_shifts[b]
            // choose by from valid_shifts[cf[w - b]]
            for (int bx_cand : valid_shift[b]) {
                for (int by_cand : valid_shift[cf[w - b]]) {
                    if (bx_cand != by_cand) {
                        bx = bx_cand;
                        by = by_cand;
                        initial_shift = b;
                        break;
                    }
                }
                if (bx != -1) break;
            }
        }
    }

    if (bx == -1) {
        for (int b : bricks) {
            if (w % b == 0) {
                if (bx == -1)bx = b;
                else by = b;
            }
            if (by != -1) break;
        }

        if (by == -1) {
            cout << "impossible" << endl;
            return 0;
        }
        // assert(lcm(bx, by) == w)
        cout << "possible" << endl;
        cout << w / bx << endl;
        for (int i = 0; i < w / bx; ++i)cout << bx << ' ';
        cout << '\n';
        cout << w / by << endl;
        for (int i = 0; i < w / by; ++i)cout << by << ' ';
        cout << '\n';
        return 0;
    }

    int b_small = min(bx, by);
    {
        int ptr = w - initial_shift - cf[w - initial_shift];
        while (ptr > 0) {
            int shift = cf[ptr];
            b_small = min(b_small, valid_shift[shift][0]);
            ptr -= shift;
        }
    }

    // new coin change with only big bricks

    vector<int> nbricks;
    for (int b : bricks) {
        if (b > b_small)nbricks.push_back(b);
    }
    for (int i = 1; i <= w; ++i) {
        valid_shift[i].clear();
        cf[i] = -1;
        sols.reset(i);
    }
    for (int b : nbricks) {
        for (int k = 1; k * b <= w; ++k) {
            valid_shift[k * b].push_back(b);
        }
    }
    for (int b = 1; b <= w; ++b) {
        if (valid_shift[b].empty()) continue;
        delta = (sols << b) & ~sols;
        sols |= delta;
        while (delta.count()) {
            int bit = delta._Find_first();
            cf[bit] = b;
            delta.reset(bit);
        }
        if (cf[w] != -1) break;
    }
    int b_small_count = 0;
    for (int i = 1; i * b_small < w; ++i) {
        if (cf[w - i * b_small] != -1) {
            b_small_count = i;
            break;
        }
    }

    vector<int> sol(b_small_count, b_small);
    {
        int ptr = w - b_small * b_small_count;
        while (ptr > 0) {
            int shift = cf[ptr];
            int b_here = valid_shift[shift][0];
            for (int i = 0; i < shift / b_here; ++i) {
                sol.push_back(b_here);
            }
            ptr -= shift;
        }
        sort(all(sol));
    }
    int b_nsmall = sol[b_small_count];
    int b_nsmall_count = 0;
    for (int i = b_small_count; i < sol.size(); ++i) {
        if (sol[i] == b_nsmall)++b_nsmall_count;
        else break;
    }

    {
        vector<int> nsol;
        for (int i = b_small_count + b_nsmall_count; i < sol.size(); ++i) {
            nsol.push_back(sol[i]);
        }
        swap(sol, nsol);
    }

    vector<int> row1, row2;
    if ((b_small * b_small_count) % b_nsmall == 0) {
        row1.push_back(b_nsmall);
        for (int b : sol)row1.push_back(b);
        int extra = (b_small * b_small_count) / b_nsmall;
        for (int i = 0; i < b_nsmall_count - 1 + extra; ++i) {
            row1.push_back(b_nsmall);
        }

        row2.push_back(b_small);
        for (int b : sol)row2.push_back(b);
        for (int i = 0; i < b_nsmall_count; ++i)row2.push_back(b_nsmall);
        for (int i = 0; i < b_small_count - 1; ++i)row2.push_back(b_small);
    } else {
        row1.push_back(b_nsmall);
        for (int b : sol)row1.push_back(b);
        for (int i = 0; i < b_nsmall_count - 1; ++i)row1.push_back(b_nsmall);
        for (int i = 0; i < b_small_count; ++i)row1.push_back(b_small);

        row2.push_back(b_small);
        for (int b : sol)row2.push_back(b);
        for (int i = 0; i < b_small_count - 1; ++i)row2.push_back(b_small);
        for (int i = 0; i < b_nsmall_count; ++i)row2.push_back(b_nsmall);
    }

    // assert(check(row1, row2 ,w));

    cout << "possible" << endl;
    cout << row1.size() << endl;
    for (auto b : row1)cout << b << ' ';
    cout << endl;
    cout << row2.size() << endl;
    for (auto b : row2)cout << b << ' ';
    cout << endl;
}
