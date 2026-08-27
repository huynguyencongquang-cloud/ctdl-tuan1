#include <iostream>

using namespace std;

long long dao_nguoc(long long n) {
    long long res = 0;
    bool is_negative = (n < 0);
    if (is_negative) n = -n;
    
    while (n > 0) {
        res = res * 10 + (n % 10);
        n /= 10;
    }
    
    return is_negative ? -res : res;
}

int main() {
    long long n;
    if (cin >> n) {
        cout << dao_nguoc(n) << endl;
    }
    return 0;
}