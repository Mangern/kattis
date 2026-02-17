#include <bits/stdc++.h>
using namespace std;

int avail[7][24];

int main() {
    int n;
    cin >> n;

    const map<string, int> daymap = {
        {"Monday", 0},
        {"Tuesday", 1},
        {"Wednesday", 2},
        {"Thursday", 3},
        {"Friday", 4},
        {"Saturday", 5},
        {"Sunday", 6},
    };

    string days;
    for (int i = 0; i < n; ++i) {
        cin >> days;
        cin >> days;

        int k;
        cin >> k;

        int d = daymap.at(days);
        for (int j = 0; j < k; ++j) {
            int h; cin >> h;
            ++avail[d][h];
        }
    }

    int mavail = 0;
    int md = 0;
    int mh = 0;
    for (int d = 0; d < 7; ++d) {
        for (int h = 0; h < 24; ++h) {
            if (avail[d][h] > mavail) {
                mavail = avail[d][h];
                md = d;
                mh = h;
            }
        }
    }

    for (auto [ds, k] : daymap) {
        if (k == md) days = ds;
    }

    cout << "Your professor should host office hours " << days << " @ " << setfill('0') << setw(2) << fixed << mh << ":00" << endl;
}
