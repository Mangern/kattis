#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

//#define PRINTALL

int n, m;
int state[10 * 10];
string moves;
int lpos;

void print() {
    cout << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << state[i * m + j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int getpos(int val) {
    for (int i = 0; i < n * m; ++i) {
        if (state[i] == val)return i;
    }
    assert(false); // unreachable
}

void U() {
    int li = lpos / m;
    int lj = lpos % m;
    if (li == n - 1)return;

    int pos = (li + 1) * m + lj;
    swap(state[pos], state[lpos]);
    lpos = pos;
    moves.push_back('U');

#ifdef PRINTALL
    print();
#endif // PRINTALL

}

void D() {
    int li = lpos / m;
    int lj = lpos % m;
    if (li == 0)return;

    int pos = (li - 1) * m + lj;
    swap(state[pos], state[lpos]);
    lpos = pos;
    moves.push_back('D');
#ifdef PRINTALL
    print();
#endif // PRINTALL
}

void L() {
    int li = lpos / m;
    int lj = lpos % m;
    if (lj == m - 1)return;

    int pos = li * m + lj + 1;
    swap(state[pos], state[lpos]);
    lpos = pos;
    moves.push_back('L');
#ifdef PRINTALL
    print();
#endif // PRINTALL
}

void R() {
    int li = lpos / m;
    int lj = lpos % m;
    if (lj == 0)return;

    int pos = li * m + lj - 1;
    swap(state[pos], state[lpos]);
    lpos = pos;
    moves.push_back('R');
#ifdef PRINTALL
    print();
#endif // PRINTALL
}

void solve2x2() {
    int tl = (n - 2) * m + m - 2;
    int tr = (n - 2) * m + m - 1;
    int bl = (n - 1) * m + m - 2;
    int br = (n - 1) * m + m - 1;
    for (int i = 0; i < 20; ++i) {
        if (state[tl] == tl+1 && state[tr] == tr+1 && state[bl] == bl+1)return;
        if (tl == lpos) {
            U();
        } else if (bl == lpos) {
            L();
        } else if (br == lpos) {
            D();
        } else {
            R();
        }
    }
    cout << "impossible" << endl;
    exit(0);
}


void mov(int from, int to) {
    if (lpos % m == from % m) {
        if (lpos % m == m - 1)R();
        else L();
    }
    while (lpos / m > from / m) {
        D();
    }
    while (lpos / m < from / m) {
        U();
    }

    if (lpos % m > from % m) {
        while (lpos != from)R();
        mov(from+1, to);
        return;
    }

    while (lpos % m < from % m - 1) {
        L();
    }


    if (from / m == n - 1) {
        D();L();U();R();D();
        from -= m;
    }

    while (from % m > to % m + 1) {
        L();U();R();R();D();
        --from;
    }

    if (from % m == to % m + 1) {
        L();
        --from;
    }

    while (from % m < to % m) {
        U();L();L();D();R();
        ++from;
    }

    if (lpos % m == from % m + 1) {
        while (from / m > to / m) {
            D();R();U();L();D();
            from -= m;
        }

        while (from / m < to / m) {
            U();R();D();L();U();
            from += m;
        }
    } else {
        assert(lpos % m == from % m - 1);
        while (from / m > to / m) {
            D();L();U();R();D();
            from -= m;
        }

        while (from / m < to / m) {
            U();L();D();R();U();
            from += m;
        }
    }
}

void solvenx2(int row) {
    if (row == n - 2) {
        solve2x2();
        return;
    }

    int tr = row * m + m;
    int tl = row * m + m - 1;

    if (state[tl - 1] == tl && state[tr - 1] == tr) {
        solvenx2(row + 1);
        return;
    }


    int g = getpos(tr);
    mov(g, tl - 1);


    if (state[tr - 1 + m] == tl) {
        R();U();L();U();R();D();D();L();U();R();U();L();D();
    } else {
        U();
        mov(getpos(tl), tl - 1 + m);
    }
    assert(state[tl - 1] == tr);
    assert(state[tl - 1 + m] == tl);
    assert(lpos == tl + m);

    D();R();U();

    solvenx2(row + 1);
}


void solve2xn() {

    int n_ = n;
    int m_ = m;
    int lpos_ = lpos;
    int saves[100];
    memcpy(saves, state, 100 * sizeof(int));
    string moves_ = moves;

    moves.clear();

    map<int,int> remap;

    for (int i = 0; i < m; ++i) {
        remap[m * (n - 2) + i+1] = 2 * i + 1;
        remap[m * (n - 1) + i+1] = 2 * i + 2;
    }

    for (int i = 0; i < m; ++i) {
        state[i * 2] = remap[saves[(n - 2) * m + i]];
        state[i * 2 + 1] = remap[saves[(n - 1) * m + i]];
    }

    n = m;
    m = 2;
    lpos = getpos(n * m);

    solvenx2(0);

    n = n_;
    m = m_;
    lpos = lpos_;
    memcpy(state, saves, 100 * sizeof(int));

    swap(moves, moves_);

    for (char c : moves_) {
        if (c == 'L')U();
        if (c == 'R')D();
        if (c == 'U')L();
        if (c == 'D')R();
    }
}

void solve(int row) {
    if (row == n - 2) {
        solve2xn();
        return;
    }

    int tr = row * m + m;
    int tl = row * m + 1;


    while (lpos / m > row + 1) {
        D();
    }
    while (lpos / m < row + 1) {
        U();
    }

    while (lpos % m > 0) {
        R();
    }

    for (int i = tr; i >= tl; --i) {
        assert(lpos == (row + 1) * m);

        int g = getpos(i);

        if (g / m == row) {
            while (lpos % m < g % m)L();

            D();R();U();U();L();D();R();D();L();U();R();U();
        }


        mov(getpos(i), tl - 1 + m);

        for (int j = 0; j < tr - i - 1; ++j) {
            L();
        }
        D();

        for (int j = 0; j < tr - min(i, tr-1); ++j) {
            R();
        }
        U();
    }

    solve(row+1);
}

void cleanup() {
    static const map<char,char> oppo{
        {'U', 'D'},
        {'D', 'U'},
        {'R', 'L'},
        {'L', 'R'},
    };
    string res;

    for (char c : moves) {
        if (res.empty()) {
            res.push_back(c);
            continue;
        }

        if (res.back() == oppo.at(c)) {
            res.pop_back();
        } else {
            res.push_back(c);
        }
    }

    //cout << moves.size() << " -> " << res.size() << endl;
    moves = res;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n * m; ++i)cin >> state[i];
    lpos = n * m - 1;

    if (m == 2) {
        solvenx2(0);
    } else {
        solve(0);
    }

    //print();


    cleanup();
    cout << moves << endl;

    //cout << moves.size() << endl;

    return 0;
}
