#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T-->0) {
        map<vector<int>, int> set_id;
        vector<vector<int>> sets;
        set_id[vector<int>()] = 0;
        sets.push_back(vector<int>());

        auto normalize = [](vector<int>& v) {
            sort(begin(v), end(v));
            v.erase(unique(begin(v), end(v)), end(v));
        };

        auto getid = [&](const vector<int>& v) {
            if (set_id.count(v))return set_id[v];
            int id = sets.size();
            sets.push_back(v);
            return set_id[v] = id;
        };

        int P = 1;
        int n;
        cin >> n;

        vector<int> stack;

        while (n-->0) {
            string cmd;
            cin >> cmd;

            if (cmd == "PUSH") {
                stack.push_back(0);
            } else if (cmd == "DUP") {
                stack.push_back(stack.back());
            } else if (cmd == "ADD") {
                int tp = stack.back(); stack.pop_back();
                int base = stack.back(); stack.pop_back();

                vector<int> result = sets[base];
                result.push_back(tp);
                normalize(result);

                stack.push_back(getid(result));
            } else if (cmd == "UNION") {
                int a = stack.back(); stack.pop_back();
                int b = stack.back(); stack.pop_back();
                vector<int> result;
                for (auto x : sets[a])result.push_back(x);
                for (auto x : sets[b])result.push_back(x);
                normalize(result);
                stack.push_back(getid(result));
            } else if (cmd == "INTERSECT") {
                int a = stack.back(); stack.pop_back();
                int b = stack.back(); stack.pop_back();
                set<int> in_a(begin(sets[a]), end(sets[a]));
                vector<int> result;
                for (auto x : sets[b]) if (in_a.count(x)) {
                    result.push_back(x);
                }
                stack.push_back(getid(result));
            } else {
                assert(false && "Not implemented");
            }

            cout << sets[stack.back()].size() << '\n';
        }
        cout << "***\n";
    }
}
