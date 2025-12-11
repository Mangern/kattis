#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    while (s.back() != 'a' && s.back() != 'e' && s.back() != 'i' && s.back() != 'o' && s.back() != 'u')s.pop_back();
    cout << s << "ntry" << endl;
}
