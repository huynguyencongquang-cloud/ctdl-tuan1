#include <iostream>
#include <vector>

using namespace std;

bool la_nguyen_to(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

vector<int> sang_eratosthenes(int n) {
    vector<bool> is_prime(n + 1, true);
    vector<int> primes;
    if (n < 2) return primes;
    
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }
    
    for (int p = 2; p <= n; p++) {
        if (is_prime[p]) primes.push_back(p);
    }
    return primes;
}

int main() {
    int n;
    if (cin >> n) {
        vector<int> res = sang_eratosthenes(n);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << (i == res.size() - 1 ? "" : " ");
        }
        cout << endl;
    }
    return 0;
}