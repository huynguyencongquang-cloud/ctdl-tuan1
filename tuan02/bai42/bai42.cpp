#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

pair<long long, int> cua_so_truot(const vector<int>& a, int k) {
    int n = a.size();
    if (n < k || k <= 0) return {0, -1};

    long long current_sum = 0;
    for (int i = 0; i < k; i++) {
        current_sum += a[i];
    }

    long long max_sum = current_sum;
    int best_start = 0;

    for (int i = k; i < n; i++) {
        current_sum += a[i] - a[i - k];
        if (current_sum > max_sum) {
            max_sum = current_sum;
            best_start = i - k + 1;
        }
    }

    return {max_sum, best_start};
}

int main() {
    int n, k;
    if (cin >> n >> k) {
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
        pair<long long, int> res = cua_so_truot(a, k);
        cout << res.first << " " << res.second << endl;
    }
    return 0;
}