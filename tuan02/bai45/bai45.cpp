#include <iostream>

using namespace std;

long long luy_thua_mod(long long a, long long b, long long m) {
    long long r = 1 % m; 
    a %= m;
    while (b > 0) {
        if (b & 1) {
            r = (__int128)r * a % m;
        }
        a = (__int128)a * a % m;
        b >>= 1;
    }
    return r;
}

int main() {
    long long a, b, m;
    if (cin >> a >> b >> m) {
        cout << luy_thua_mod(a, b, m) << endl;
    }
    return 0;
}