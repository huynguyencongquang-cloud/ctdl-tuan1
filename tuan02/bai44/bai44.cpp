#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void bubble_sort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    vector<int> sizes = {1000, 2000, 4000, 8000};
    cout << "Kich thuoc n | Thoi gian (s)" << endl;
    for (int n : sizes) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = n - i; 
        
        auto t0 = chrono::steady_clock::now();
        bubble_sort(a);
        auto t1 = chrono::steady_clock::now();
        
        chrono::duration<double> diff = t1 - t0;
        cout << n << "         | " << diff.count() << endl;
    }
    return 0;
}