#include <iostream>
#include <climits>

using namespace std;

bool giai_thua(int n, long long &kq) {
    if (n < 0) return false;
    kq = 1;
    for (int i = 1; i <= n; i++) {
        if (LLONG_MAX / i < kq) {
            return false; // Bị tràn số
        }
        kq *= i;
    }
    return true;
}

int main() {
    int n;
    if (cin >> n) {
        long long kq;
        if (giai_thua(n, kq)) {
            cout << kq << endl;
        } else {
            cout << "Tran so" << endl;
        }
    }
    return 0;
}