#include <bits/stdc++.h>
using namespace std;
int main() {
    unordered_set<int> has;
    int n, q;
    cin >> n >> q;
    while (q-->0) {
        int t;
        cin >> t;
        if (t == 1) {
            int i;
            cin >> i;
            if (has.count(i)) {
                cout << "Upptagen\n";
            } else {
                cout << "Ledig\n";
                has.insert(i);
            }
        } else {
            int i, j;
            cin >> i >> j;
            if (has.count(j)) {
                cout << "Upptagen\n";
            } else {
                cout << "Ledig\n";
                has.erase(i);
                has.insert(j);
            }
        }
    }
}
