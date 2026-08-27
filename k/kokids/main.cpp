#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    s = "R" + s;

    int ptr = 1;
    int ans = 0;
    for (int i = 0; i < k; ++i) {
        while (ptr <= n) {
            char jump = s[ptr-1] ^ 'L' ^ 'R';
            if (jump != s[ptr]) {
                break;
            }
            ++ptr;
        }
        if (ptr == n+1)++ans;
        else ++ptr;
    }
    cout << ans << endl;
}
