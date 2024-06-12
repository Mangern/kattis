#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    unordered_map<string, unordered_set<string>> ws;
    unordered_map<string, int> use;
    string line;
    getline(cin, line);
    n = stoi(line);
    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        stringstream ss(line);
        string user;
        string str;
        ss >> user;
        while (ss >> str) {
            ws[user].insert(str);
            ++use[str];
        }
    }
    unordered_set<string> all = ws.begin()->second;

    for (const auto& [u, w] : ws) {
        for (auto it = all.begin(); it != all.end(); ) {
            if (!w.count(*it)) {
                it = all.erase(it);
            } else ++it;
        }
    }
    if (all.empty()) {
        cout << "ALL CLEAR" << endl;
    } else {
        vector<string> ans(all.begin(), all.end());
        sort(ans.begin(), ans.end(), [&] (const auto& a, const auto& b) {
            if (use[a] == use[b])return a < b;
            return use[a] > use[b];
        });
        for (auto s : ans)cout << s << endl;
    }
}
