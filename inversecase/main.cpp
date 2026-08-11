#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    getline(cin, line);

    for (char c : line) {
        if (!isalpha(c)){cout<<c;continue;}
        char d = c ^ ('a' - 'A');
        cout << d;
    }
    cout << endl;
}
