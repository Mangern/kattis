#include <iostream>
#include <list>

using namespace std;

const int mxN = 1e5+5;

list<string> strs[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        strs[i].push_back(s);
    }

    int has = 0;
    for (int k = 0; k < n - 1; ++k) {
        int i, j;
        cin >> i >> j, --i, --j;
        strs[i].splice(strs[i].end(), strs[j]);
        has = i;
    }

    for (const auto& s : strs[has]) {
        cout << s;
    }
    cout << endl;
}
