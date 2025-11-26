#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    getline(cin,s);
    int pos = 0;

    int ans = 0;
    for (;;) {
        pos = s.find("certainly", pos);
        if (pos == string::npos)break;
        ++ans;
        pos += 7;
    }
    cout << ans << endl;
}
