#include <bits/stdc++.h>
using namespace std;

string normalize(string line) {
    string result;

    int i;
    for (i = 0; i < line.length() && isspace(line[i]); ++i);

    while (!line.empty() &&isspace(line.back()))line.pop_back();

    for (auto c : line) 
        if (result.empty() || 
          !(isspace(result.back()) && isspace(c)))
            result.push_back(c);

    return result;
}

void chop_add(vector<string>& chunk, vector<string>& all_lines) {
    all_lines.pop_back();
    while (all_lines.size() > 1 && all_lines.back() != "***END***") {
        chunk.push_back(all_lines.back());
        all_lines.pop_back();
    }

    reverse(begin(chunk), end(chunk));
}

int lcs(const vector<string>& a, const vector<string>& b) {
    int n = a.length();
    int m = b.length();
    int ans = 0;

    for (int i = 0; i < m; ++i) {
    }
}

int main() {
    string line;
    vector<string> all_lines;
    while (getline(cin, line)) {
        string n = normalize(line);
        if (n.length())all_lines.push_back(n);
    }

    vector<vector<string>> repos;
    vector<string> prog;

    chop_add(prog, all_lines);

    while (all_lines.size() > 1) {
        repos.push_back(vector<string>());
        chop_add(repos.back(), all_lines);
    }

    for (auto s : prog)cout << s << endl;
    cout << endl;

    for (auto v : repos) {
        for (auto s : v)cout << s << endl;
        cout << endl;
    }
}
