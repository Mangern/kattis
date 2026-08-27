#include <bits/stdc++.h>
using namespace std;

bool solve(const string& s) {
    set<string> vars;
    set<string> nvars;

    stringstream ss(s);
    string tok;
    while (ss >> tok) {
        if (tok == "OR") continue;

        if (tok[0] == '!') {
            nvars.insert(tok.substr(1,tok.length()));
        } else {
            vars.insert(tok);
        }
    }

    bool good=1;
    for (auto v : vars) {
        if (nvars.count(v)) {
            good = 0;
            break;
        }
    }
    return good;
}

int main() {
    string content;
    getline(cin,content);

    for (int i = 0; i < content.length(); ) {
        if (content[i] == '(') {
            int j = content.find(')', i);
            if (solve(content.substr(i+1, j - 1 - i))) {
                cout << "Jebb" << endl;
                return 0;
            }
            i = j;
        } else ++i;
    }
    cout << "Neibb" << endl;
}
