#include <iostream>
#include <vector>

using namespace std;

long long dem = 0;

long long fib_de_quy(int n) {
    dem++;
    if (n <= 1) return n;
    return fib_de_quy(n - 1) + fib_de_quy(n - 2);
}

long long fib_ghi_nho_helper(int n, vector<long long>& memo) {
    dem++;
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fib_ghi_nho_helper(n - 1, memo) + fib_ghi_nho_helper(n - 2, memo);
    return memo[n];
}

long long fib_ghi_nho(int n) {
    vector<long long> memo(n + 1, -1);
    return fib_ghi_nho_helper(n, memo);
}

long long fib_lap(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1, c = 0;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int n;
    if (cin >> n) {
        dem = 0;
        long long val1 = fib_de_quy(n);
        long long call1 = dem;

        dem = 0;
        long long val2 = fib_ghi_nho(n);
        long long call2 = dem;

        long long val3 = fib_lap(n);

        cout << val1 << " " << call1 << " " << call2 << endl;
    }
    return 0;
}