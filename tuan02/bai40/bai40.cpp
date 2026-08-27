#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct KetQua {
    long long tong;
    int dau;
    int cuoi;
};

KetQua kadane_chi_so(const vector<int>& a) {
    if (a.empty()) return {0, -1, -1};
    
    long long max_sum = a[0];
    long long current_sum = a[0];
    int start = 0, temp_start = 0, end = 0;
    
    for (size_t i = 1; i < a.size(); i++) {
        if ((long long)a[i] > current_sum + a[i]) {
            current_sum = a[i];
            temp_start = i;
        } else {
            current_sum += a[i];
        }
        
        if (current_sum > max_sum) {
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }
    }
    return {max_sum, start, end};
}

int main() {
    int n;
    if (cin >> n) {
        string temp;
        vector<int> a;
        if (cin >> temp && temp != "/") {
            a.push_back(stoi(temp));
            for (int i = 1; i < n; i++) {
                int x; cin >> x;
                a.push_back(x);
            }
        } else {
            for (int i = 0; i < n; i++) {
                int x; cin >> x;
                a.push_back(x);
            }
        }
        KetQua kq = kadane_chi_so(a);
        cout << kq.tong << " " << kq.dau << " " << kq.cuoi << endl;
    }
    return 0;
}