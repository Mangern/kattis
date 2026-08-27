#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

deque<int> parse(const string& s) {
    if (s.length() == 2)return deque<int>();
    int ptr = 1;
    deque<int> res;

    for (int i = 1; i < s.length(); ++i) {
        if (s[i] == ',' || s[i] == ']') {
            res.push_back(stoi(s.substr(ptr, i - ptr)));
            ptr = i+1;
        }
    }
    return res;
}

void solve() {
    string prog;
    cin >> prog;

    int n;
    cin >> n;
    string arrs;
    cin >> arrs;
    deque<int> a = parse(arrs);
    bool rev = 1;

    for (char c : prog) {
        if (c == 'R') {
            rev = !rev;
            continue;
        }
        if (a.empty()) {
            cout << "error" << endl;
            return;
        }
        if (rev)a.pop_front();
        else a.pop_back();
    }
    cout << "[";
    if (!rev) {
        while (a.size()) {
            cout << a.back();
            a.pop_back();
            if (a.size())cout << ',';
        }
    } else {
        while (a.size()) {
            cout << a.front();
            a.pop_front();
            if (a.size())cout << ',';
        }
    }
    cout << "]" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T-->0) {
        solve();
    }
}
