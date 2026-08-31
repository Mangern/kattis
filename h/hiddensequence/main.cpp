#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;

    int ptr1 = 0, ptr2 = 0, ptr3 = 0;

    a.push_back('a');
    b.push_back('b');
    c.push_back('c');

    while (ptr1 < a.length()-1 || ptr2 < b.length()-1 || ptr3 < c.length()-1) {
        if (a[ptr1] == b[ptr2]) {
            cout << a[ptr1];
            ++ptr1;
            ++ptr2;
        } else if (a[ptr1] == c[ptr3]) {
            cout << a[ptr1];
            ++ptr1;
            ++ptr3;
        } else if (b[ptr2] == c[ptr3]) {
            cout << b[ptr2];
            ++ptr2;
            ++ptr3;
        }
    }
    cout << endl;
}
