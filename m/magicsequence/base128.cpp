#include <cstring>
#pragma GCC optimize("O3", "unroll-loops")
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int mxN = 1e6+6;

int _arr1[mxN];
int _arr2[mxN];
int cnt[128];

inline void solve() {
    int n;
    cin >> n;
    ll a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int* arr = _arr1;
    int* barr = _arr2;

    arr[0] = a;

    b %= c;
    a %= c;

    for (int i = 1; i < n; ++i) {
        arr[i] = (arr[i-1] * b + a) % c;
    }
    for (int k = 0; k < 30; k += 7) {
        int ptr = 0;
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < n; ++i) {
            ++cnt[(arr[i]>>k)&0b1111111];
        }
        cnt[1] += cnt[0];
        cnt[2] += cnt[1];
        cnt[3] += cnt[2];
        cnt[4] += cnt[3];
        cnt[5] += cnt[4];
        cnt[6] += cnt[5];
        cnt[7] += cnt[6];
        cnt[8] += cnt[7];
        cnt[9] += cnt[8];
        cnt[10] += cnt[9];
        cnt[11] += cnt[10];
        cnt[12] += cnt[11];
        cnt[13] += cnt[12];
        cnt[14] += cnt[13];
        cnt[15] += cnt[14];
        cnt[16] += cnt[15];
        cnt[17] += cnt[16];
        cnt[18] += cnt[17];
        cnt[19] += cnt[18];
        cnt[20] += cnt[19];
        cnt[21] += cnt[20];
        cnt[22] += cnt[21];
        cnt[23] += cnt[22];
        cnt[24] += cnt[23];
        cnt[25] += cnt[24];
        cnt[26] += cnt[25];
        cnt[27] += cnt[26];
        cnt[28] += cnt[27];
        cnt[29] += cnt[28];
        cnt[30] += cnt[29];
        cnt[31] += cnt[30];
        cnt[32] += cnt[31];
        cnt[33] += cnt[32];
        cnt[34] += cnt[33];
        cnt[35] += cnt[34];
        cnt[36] += cnt[35];
        cnt[37] += cnt[36];
        cnt[38] += cnt[37];
        cnt[39] += cnt[38];
        cnt[40] += cnt[39];
        cnt[41] += cnt[40];
        cnt[42] += cnt[41];
        cnt[43] += cnt[42];
        cnt[44] += cnt[43];
        cnt[45] += cnt[44];
        cnt[46] += cnt[45];
        cnt[47] += cnt[46];
        cnt[48] += cnt[47];
        cnt[49] += cnt[48];
        cnt[50] += cnt[49];
        cnt[51] += cnt[50];
        cnt[52] += cnt[51];
        cnt[53] += cnt[52];
        cnt[54] += cnt[53];
        cnt[55] += cnt[54];
        cnt[56] += cnt[55];
        cnt[57] += cnt[56];
        cnt[58] += cnt[57];
        cnt[59] += cnt[58];
        cnt[60] += cnt[59];
        cnt[61] += cnt[60];
        cnt[62] += cnt[61];
        cnt[63] += cnt[62];
        cnt[64] += cnt[63];
        cnt[65] += cnt[64];
        cnt[66] += cnt[65];
        cnt[67] += cnt[66];
        cnt[68] += cnt[67];
        cnt[69] += cnt[68];
        cnt[70] += cnt[69];
        cnt[71] += cnt[70];
        cnt[72] += cnt[71];
        cnt[73] += cnt[72];
        cnt[74] += cnt[73];
        cnt[75] += cnt[74];
        cnt[76] += cnt[75];
        cnt[77] += cnt[76];
        cnt[78] += cnt[77];
        cnt[79] += cnt[78];
        cnt[80] += cnt[79];
        cnt[81] += cnt[80];
        cnt[82] += cnt[81];
        cnt[83] += cnt[82];
        cnt[84] += cnt[83];
        cnt[85] += cnt[84];
        cnt[86] += cnt[85];
        cnt[87] += cnt[86];
        cnt[88] += cnt[87];
        cnt[89] += cnt[88];
        cnt[90] += cnt[89];
        cnt[91] += cnt[90];
        cnt[92] += cnt[91];
        cnt[93] += cnt[92];
        cnt[94] += cnt[93];
        cnt[95] += cnt[94];
        cnt[96] += cnt[95];
        cnt[97] += cnt[96];
        cnt[98] += cnt[97];
        cnt[99] += cnt[98];
        cnt[100] += cnt[99];
        cnt[101] += cnt[100];
        cnt[102] += cnt[101];
        cnt[103] += cnt[102];
        cnt[104] += cnt[103];
        cnt[105] += cnt[104];
        cnt[106] += cnt[105];
        cnt[107] += cnt[106];
        cnt[108] += cnt[107];
        cnt[109] += cnt[108];
        cnt[110] += cnt[109];
        cnt[111] += cnt[110];
        cnt[112] += cnt[111];
        cnt[113] += cnt[112];
        cnt[114] += cnt[113];
        cnt[115] += cnt[114];
        cnt[116] += cnt[115];
        cnt[117] += cnt[116];
        cnt[118] += cnt[117];
        cnt[119] += cnt[118];
        cnt[120] += cnt[119];
        cnt[121] += cnt[120];
        cnt[122] += cnt[121];
        cnt[123] += cnt[122];
        cnt[124] += cnt[123];
        cnt[125] += cnt[124];
        cnt[126] += cnt[125];
        cnt[127] += cnt[126];

        for (int i = n - 1; i >= 0; --i) {
            barr[(cnt[(arr[i]>>k)&0b1111111]--) -1] = arr[i];
        }
        swap(arr, barr);
    }
    ll v = 0;
    for (int i = 0; i < n; ++i) {
        v = (v * x + arr[i]) % y;
    }
    cout << v << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc;
    cin >> tc;
    while (tc-->0)solve();
}
