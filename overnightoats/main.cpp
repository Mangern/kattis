#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;


    queue<int> q;
    bool fail = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        if (s == "ADD") {
            q.push(i);
        } else if (s == "PASS") continue;
        else {
            if (i - q.front() > x) {
                fail = 1;
            }
            q.pop();
        }
    }
    cout << (fail?"ono.." : "yay!") << endl;
}
