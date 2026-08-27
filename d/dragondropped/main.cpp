#include <cassert>
#include <iostream>
#include <string>

using namespace std;
using ll = long long;

const string NAME[2] = {
    "GABBY",
    "SPIKE"
};

const int MX = 30000;
int COUNT = 0;

// N = 21
// END = 4
// 0 -> 1 -> 2 -> 1
// G
// S

void done(int id) {
    cout << "ASK " << NAME[id] << endl;
    exit(0);
}

// true if equal *after* the steps
bool advance(int id, int steps) {
    //assert(COUNT < MX);
    ++COUNT;
    int e;
    int s;
    for (int i = 0; i < steps; ++i) {
        cout << "NEXT " << NAME[id] << endl;
        cin >> s >> e;
        if (s == 0)done(id);
    }
    return e;
}

void ret(int id) {
    //assert(COUNT < MX);
    cout << "RETURN " << NAME[id] << endl;
    ++COUNT;

    int s,e;
    cin >> s >> e;
}

ll N;
int j;

int main() {
    cin >> N;

    for (int i = 0; i < 6000; ++i) {
        advance(0, 1);
    }

    for (j = 1; ; ++j) {
        if (advance(1, 1)) break;
    }

    int i;
    for (i = 1; ; ++i) {
        if (advance(0, 1)) break;
    }

    for (int k = 0; k < (N - j) % i; ++k) {
        advance(1, 1);
    }
    done(1);
}
