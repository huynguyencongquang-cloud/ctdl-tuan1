#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    long long tong = 0;
    long long nho_nhat, lon_nhat;

    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        tong += x;
        if (i == 0) {
            nho_nhat = x;
            lon_nhat = x;
        } else {
            nho_nhat = min(nho_nhat, x);
            lon_nhat = max(lon_nhat, x);
        }
    }

    double trung_binh = (double)tong / n;

    cout << tong << " " 
         << fixed << setprecision(4) << trung_binh << " " 
         << nho_nhat << " " 
         << lon_nhat << "\n";

    return 0;
}
