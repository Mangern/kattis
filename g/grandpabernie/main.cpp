#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<string, vector<int>> mp;

    for (int i = 0; i < n; ++i) {
        string s;
        int y;
        cin >> s >> y;
        mp[s].push_back(y);
    }

    for (auto& [s, ys] : mp)
        sort(begin(ys), end(ys));

    int q;
    cin >> q;
    while (q-->0) {
        string s;
        int i;
        cin >> s >> i;
        cout << mp[s].at(i-1) << endl;
    }

}
