#include <bits/stdc++.h>
using namespace std;

const int mxN = 1<<25;

int n, k;
vector<int> sizes;
vector<int> placements[5];
int miss_mask, hit_mask;
int ans;

void search(int i = 0, int cur = 0) {
    if (cur & miss_mask) return;
    if (i == k) {
        if ((cur & hit_mask) == hit_mask) {
            ++ans;
        }
        return;
    }

    for (int p : placements[i]) {
        if (cur & p) continue;
        search(i+1, cur | p);
    }
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        for (int j = 0; j < n; ++j) {
            int idx = i * n + j;
            if (s[j] == 'X') {
                miss_mask |= 1<<idx;
            }
            if (s[j] == 'O') {
                hit_mask |= 1<<idx;
            }
        }
    }

    sizes.resize(k);
    for (auto &x : sizes) cin >> x;

    for (int idx = 0; idx < k; ++idx) {
        int s = sizes[idx];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j + s <= n) {
                    int mask = 0;
                    for (int p = 0; p < s; ++p) {
                        int loc = i * n + j + p;
                        mask |= 1<<loc;
                    }
                    placements[idx].push_back(mask);
                }
                if (s > 1 && i + s <= n) {
                    int mask = 0;
                    for (int p = 0; p < s; ++p) {
                        int loc = (i+p) * n + j;
                        mask |= 1<<loc;
                    }
                    placements[idx].push_back(mask);
                }
            }
        }
    }
    search();
    cout << ans << endl;
}
