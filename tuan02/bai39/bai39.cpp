#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

long long cach1(const vector<int>& a) {
    int n = a.size();
    if (n == 0) return 0;
    long long max_sum = a[0];
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            long long sum = 0;
            for (int k = i; k <= j; k++) sum += a[k];
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
}

long long cach2(const vector<int>& a) {
    int n = a.size();
    if (n == 0) return 0;
    long long max_sum = a[0];
    for (int i = 0; i < n; i++) {
        long long sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
}

long long cach3(const vector<int>& a) {
    if (a.empty()) return 0;
    long long max_sum = a[0];
    long long current_sum = a[0];
    for (size_t i = 1; i < a.size(); i++) {
        current_sum = max((long long)a[i], current_sum + a[i]);
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}

void kiem_thu_tu_dong() {
    srand(time(0));
    bool ok = true;
    for (int test = 0; test < 100; test++) {
        int n = rand() % 50 + 1;
        vector<int> a(n);
        for (int i = 0; i < n; i++) a[i] = rand() % 200 - 100;
        
        long long r1 = cach1(a);
        long long r2 = cach2(a);
        long long r3 = cach3(a);
        
        if (r1 != r2 || r2 != r3) {
            ok = false;
            cout << "Loi o test " << test << endl;
            break;
        }
    }
    if (ok) cout << "Kiem thu 100 test: TAT CA DEU DUNG" << endl;
}

int main() {
    int n;
    if (cin >> n) {
        string temp;
        // Bỏ qua dấu '/' nếu người dùng nhập dạng '8 / 4 -3 ...'
        if (cin >> temp && temp != "/") {
            // Nếu ký tự sau n không phải '/' thì đưa nó vào phần tử đầu tiên
            vector<int> a;
            a.push_back(stoi(temp));
            for (int i = 1; i < n; i++) {
                int x; cin >> x;
                a.push_back(x);
            }
            cout << cach3(a) << endl;
            return 0;
        }
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << cach3(a) << endl;
    } else {
        kiem_thu_tu_dong();
    }
    return 0;
}