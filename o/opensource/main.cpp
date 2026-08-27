#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    string proj;
    map<string, set<string>> cnt;
    map<string, set<string>> stud;

    while (getline(cin, line)) {
        if (line[0] == '0') break;

        if (line[0] == '1') {
            // output answer

            for (auto [stud, projs] : stud) {
                if (projs.size() > 1) {
                    for (auto p : projs) {
                        cnt[p].erase(stud);
                    }
                }
            }

            vector<pair<int, string>> ans;

            for (auto [k, v] : cnt) {
                ans.push_back({-(int)v.size(), k});
            }

            sort(begin(ans), end(ans));

            for (auto [cnt, s] : ans) {
                cout << s << " " << -cnt << endl;
            }

            // reset
            cnt.clear();
            stud.clear();

            continue;
        }

        if (line[0] <= 'Z') {
            proj = line;
            cnt[proj] = set<string>();
            continue;
        } else {
            cnt[proj].insert(line);
            stud[line].insert(proj);
        }
    }
}
