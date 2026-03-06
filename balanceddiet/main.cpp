#include <bits/stdc++.h>
using namespace std;

const int mxN = 21;
int nums[mxN];

int main() {
    for (;;) {
        int n;
        scanf("%d", &n);
        if (!n) break;

        int sum = 0;

        for (int i = 0; i < n; ++i) {
            scanf("%d", &nums[i]);
            sum += nums[i];
        }

        int lft = n / 2;
        int rgt = n - lft;

        vector<int> lvals, rvals;
        for (int mask = 0; mask < (1<<lft); ++mask) {
            int cur = 0;
            for (int i = 0; i < lft; ++i) {
                if ((mask >> i) & 1) {
                    cur += nums[i];
                }
            }
            lvals.push_back(cur);
        }
        for (int mask = 0; mask < (1<<rgt); ++mask) {
            int cur = 0;
            for (int i = 0; i < rgt; ++i) {
                if ((mask >> i) & 1) {
                    cur += nums[lft+i];
                }
            }
            rvals.push_back(cur);
        }
        sort(begin(lvals), end(lvals));
        sort(begin(rvals), end(rvals));

        int best_diff = sum;
        pair<int, int> best = {sum, 0};

        for (int i = 0; i < lvals.size(); ++i) {
            int j = lower_bound(begin(rvals), end(rvals), sum / 2 - lvals[i]) - begin(rvals);

            for (int dj = -5; dj <= 5; ++dj) {
                if (j + dj >= 0 && j + dj < rvals.size()) {
                    int a = lvals[i] + rvals[j + dj];
                    int b = sum - a;
                    if (a < b)swap(a, b);
                    if (a - b < best_diff) {
                        best_diff = a - b;
                        best = {a, b};
                    }
                }
            }
        }

        printf("%d %d\n", best.first, best.second);
    }
}
