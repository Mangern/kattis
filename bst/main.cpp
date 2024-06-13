#include <iostream>
#include <iterator>
#include <map>
#include <set>

using namespace std;

const int mxN = 3e5+5;

long long ans;

set<int> nodes;
int depth[mxN];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (i == 0) {
            nodes.insert(x);
        } else {
            auto [it, succ] = nodes.insert(x);
            int d_right = -1;
            int d_left = -1;
            int rgt = 0;
            int lft = 0;

            if (next(it, 1) != nodes.end()) {
                rgt = *next(it, 1);
                d_right = depth[rgt];
            }
            if (it != nodes.begin()) {
                lft = *next(it, -1);
                d_left = depth[lft];
            }

            if (d_left > d_right) {
                depth[x] = depth[lft] + 1;
            } else {
                depth[x] = depth[rgt] + 1;
            }
            ans += depth[x];
        }

        cout << ans << endl;
    }
}
