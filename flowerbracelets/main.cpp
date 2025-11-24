#include <bits/stdc++.h>
using namespace std;

string s;

int cur_idx;

void lex_reset() {
    cur_idx = 0;
}

char peek() {
    if (cur_idx >= s.length())return EOF;

    return s[cur_idx];
}

void advance() {
    ++cur_idx;
}

bool parse_butt() {
    if (peek() != 'b') return false;
    advance();
    return true;
}

bool parse_clovers() {
    if (peek() != 'c')return false;
    advance();
    if (peek() != 'c')return false;
    advance();
    return true;
}

bool parse_flowers();

bool parse_daisies() {
    if (peek() != 'd') return false;
    advance();
    if (!parse_flowers()) return false;
    if (peek() != 'd')return false;
    advance();
    return true;
}

bool parse_sunflowers() {
    if (peek() != 's')return false;
    advance();
    if (peek() != 's')return false;
    advance();
    return parse_flowers();
}

bool parse_roses() {
    char c = peek();
    if (c == 'r') {
        advance();
        return parse_flowers();
    } else if (c == 'h') {
        advance();
        return true;
    }
    return false;
}

bool parse_flowers() {
    char c = peek();
    if (c == 'd') {
        return parse_daisies();
    }
    if (c == 's') {
        return parse_sunflowers();
    }
    if (c == 'r' || c == 'h') {
        return parse_roses();
    }
    return false;
}

bool parse() {
    if (!parse_butt()) return false;
    if (!parse_flowers()) return false;
    if (!parse_clovers()) return false;
    if (peek() != EOF) return false;
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t-->0) {
        cin >> s;

        lex_reset();

        cout << (parse() ? "authentic" : "counterfeit") << endl;
    }
}
