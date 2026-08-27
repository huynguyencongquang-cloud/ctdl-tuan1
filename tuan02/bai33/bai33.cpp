#include <iostream>
#include <utility>

using namespace std;

pair<int, int> phan_tich(long long n) {
    int so_chu_so = 0;
    int tong_chu_so = 0;
    
    if (n == 0) return {1, 0};
    if (n < 0) n = -n;
    
    while (n > 0) {
        tong_chu_so += n % 10;
        so_chu_so++;
        n /= 10;
    }
    
    return {so_chu_so, tong_chu_so};
}

int main() {
    long long n;
    if (cin >> n) {
        pair<int, int> kq = phan_tich(n);
        cout << kq.first << " " << kq.second << endl;
    }
    return 0;
}