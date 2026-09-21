#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    for (;;) {
        getline(cin, line);
        int n = stoi(line);
        if (!n) break;

        unordered_map<string, int> real;
        unordered_map<string, int> hash;

        vector<int> fake(256, 0);

        for (int i = 0; i < n; ++i) {
            getline(cin ,line);
            int x = 0;
            for (char c : line)x ^= c;
            ++real[line];
            hash[line] = x;
            ++fake[x];
        }

        int ans = 0;
        for (const auto& [line, cnt] : real) {
            int others = fake[hash[line]] - cnt;
            ans += cnt * others;
        }

        ans /= 2;

        cout << real.size() << " " << ans << '\n';
    }
}
