#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    unordered_map<string, int> evts;
    int n;
    cin >> n;

    vector<string> prv;

    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;

        if (c == 'E') {
            string e;
            cin >> e;
            evts[e] = prv.size();
            prv.push_back(e);
        } else if (c == 'D') {
            int r;
            cin >> r;

            for (int j = 0; j < r; ++j) {
                string s = prv.back();
                prv.pop_back();
                evts.erase(s);
            }
        } else {
            int k;
            cin >> k;

            bool consistent = true;
            int top = i;
            int bot = -1;
            for (int j = 0; j < k; ++j) {
                string s;
                cin >> s;
                if (s[0] == '!') {
                    s = s.substr(1);
                    if (evts.count(s)) {
                        consistent = false;
                        top = min(top, evts[s]);
                    }
                } else {
                    if (!evts.count(s)) {
                        consistent = false;
                        top = -1;
                    } else {
                        bot = max(bot, evts[s]);
                    }
                }
            }

            if (consistent) {
                cout << "Yes" << endl;
                continue;
            }
            if (bot >= top) {
                cout << "Plot Error" << endl;
                continue;
            }
            cout << prv.size() - top << " Just A Dream" << endl;
        }
    }
}
