#include <bits/stdc++.h>
using namespace std;

struct Item {
    string name;
    vector<string> args;
};

// eat a fact or query off a ss
Item parse(stringstream &ss) {
    string name;
    vector<string> args;
    string tmp;
    string arg;
    char c;
    for (;;) {
        if (!(ss >> c)) return {"", {}};
        if (c == '(') break;
        name.push_back(c);
    }


    for (;;) {
        ss >> c;
        if (c == ',' || c == ')') {
            args.push_back(arg);
            arg.clear();
        } else {
            arg.push_back(c);
        }
        if (c == ')') break;
    }
    return {name, args};
}

bool matches(const Item& fact, const Item& query) {
    if (fact.args.size() != query.args.size()) return false;
    if (fact.name != query.name) return false;
    int nargs = fact.args.size();

    unordered_map<string, string> bindings;
    for (int i = 0; i < nargs; ++i) {
        // wildcard
        if (query.args[i] == "_") {
            continue;
        }
        if (query.args[i][0] == '_') {
            // variable
            if (bindings.count(query.args[i])) {
                if (bindings.at(query.args[i]) != fact.args[i]) return false;
            } else {
                bindings[query.args[i]] = fact.args[i];
            }
        } else {
            // exact match
            if (fact.args[i] != query.args[i]) return false;
        }
    }
    return true;
}

int main() {
    string line;
    vector<Item> facts;
    while (getline(cin, line)) {
        if (line.length() == 0) break;
        stringstream ss(line);
        for (;;) {
            auto [name, args] = parse(ss);
            if (!name.length()) break;
            facts.push_back({name, args});
        }
    }

    while (getline(cin, line)) {
        stringstream ss(line);
        Item query = parse(ss);
        int count = 0;
        for (const auto & f : facts) {
            if (matches(f, query)) {
                ++count;
            }
        }
        cout << count << endl;
    }
}
