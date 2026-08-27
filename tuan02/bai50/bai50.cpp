#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <random>
#include <iomanip>

using namespace std;

// Hàm tính khoảng cách Euclid giữa 2 điểm d chiều
double kc_euclid(const vector<double>& u, const vector<double>& v, int d) {
    double sum = 0.0;
    for (int i = 0; i < d; i++) {
        double diff = u[i] - v[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

void do_thoi_gian(int n, int q = 1000, int d = 20) {
    // 1. Sinh dữ liệu ngẫu nhiên (dùng mt19937 với fixed seed)
    mt19937 rng(12345);
    uniform_real_distribution<double> dist(0.0, 1.0);

    vector<vector<double>> train(n, vector<double>(d));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) train[i][j] = dist(rng);
    }

    vector<vector<double>> test(q, vector<double>(d));
    for (int i = 0; i < q; i++) {
        for (int j = 0; j < d; j++) test[i][j] = dist(rng);
    }

    // 2. Bấm giờ quanh vòng lặp phân loại
    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < q; i++) {
        double min_dist = -1.0;
        int nearest_idx = -1;
        for (int j = 0; j < n; j++) {
            double d_val = kc_euclid(test[i], train[j], d);
            if (min_dist < 0 || d_val < min_dist) {
                min_dist = d_val;
                nearest_idx = j;
            }
        }
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;

    cout << "n = 10^" << log10(n) << " | Thoi gian: " << fixed << setprecision(4) << elapsed.count() << "s" << endl;
}

int main() {
    vector<int> N_list = {1000, 10000, 100000};
    for (int n : N_list) {
        do_thoi_gian(n);
    }
    return 0;
}