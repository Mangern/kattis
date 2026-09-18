#include <bits/stdc++.h>
using namespace std;

struct ii {
    int first;
    int second;

    ii(int a, int b) : first{a}, second{b} {}
};

const int mxN = 1001;

int n;
vector<ii> loc[mxN*mxN];

bool operator<(const ii& pt1, const ii& pt2) {
    if (pt1.second == pt2.second) return pt1.first < pt2.first;
    return pt1.second < pt2.second;
}

bool check(vector<ii>& pts) {
    // Does pts contain distinct (i, j) and (i', j') such that i <= i' and j <= j' ?
    sort(begin(pts), end(pts), [](const ii& pt1, const ii& pt2) {
        if (pt1.first == pt2.first) return pt1.second < pt2.second;
        return pt1.first < pt2.first;
    });
    // ordered by j-coordinate
    set<ii> rem(begin(pts), end(pts));
    for (auto pp : pts) {
        rem.erase(pp);
        // does rem contain something with .second >= pp.second?
        auto it = rem.lower_bound(ii{0, pp.second});
        if (it != rem.end()) {
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            scanf("%d", &x);
            loc[x].emplace_back(i, j);
        }
    }

    for (int i = 0; i < n * n; ++i) {
        if (check(loc[i])) {
            printf("0\n");
            return 0;
        }
    }
    printf("1\n");
}
