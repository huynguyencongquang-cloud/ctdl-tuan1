#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

long long tich_lon_nhat(const vector<int>& a) {
    if (a.empty()) return 0;
    
    long long max_prod = a[0];
    long long min_prod = a[0];
    long long ans = a[0];
    
    for (size_t i = 1; i < a.size(); i++) {
        if (a[i] < 0) swap(max_prod, min_prod);
        
        max_prod = max((long long)a[i], max_prod * a[i]);
        min_prod = min((long long)a[i], min_prod * a[i]);
        
        ans = max(ans, max_prod);
    }
    return ans;
}

long long tich_lon_nhat_n2(const vector<int>& a) {
    int n = a.size();
    if (n == 0) return 0;
    long long ans = a[0];
    for (int i = 0; i < n; i++) {
        long long current_prod = 1;
        for (int j = i; j < n; j++) {
            current_prod *= a[j];
            ans = max(ans, current_prod);
        }
    }
    return ans;
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
        cout << tich_lon_nhat(a) << endl;
    }
    return 0;
}