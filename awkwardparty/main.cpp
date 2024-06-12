

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    unordered_map<int, vector<int>> pos;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        pos[x].push_back(i);
    }

    int ans = n;
    for (const auto& [k, v] : pos) {
        for (int i = 1; i < v.size(); ++i) {
            ans = min(ans, v[i] - v[i-1]);
        }
    }
    cout << ans << endl;
}
