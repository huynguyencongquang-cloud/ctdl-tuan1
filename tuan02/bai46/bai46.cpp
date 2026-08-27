#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

struct Mau {
    vector<double> x;
    string y;
};

// Hàm lọc lấy các số thực từ chuỗi chứa ngoặc, dấu phẩy, chấm phẩy
vector<double> parse_numbers(const string& s) {
    vector<double> nums;
    string cleaned = s;
    for (char& c : cleaned) {
        if (c == '(' || c == ')' || c == ';' || c == ',') c = ' ';
    }
    stringstream ss(cleaned);
    double val;
    while (ss >> val) nums.push_back(val);
    return nums;
}

pair<string, double> lang_gieng_gan_nhat(const vector<double>& q, const vector<Mau>& D) {
    string nhan_tot_nhat = "";
    double min_dist = -1.0;

    for (const auto& mau : D) {
        double dist_sq = 0.0;
        for (size_t i = 0; i < q.size(); i++) {
            double diff = q[i] - mau.x[i];
            dist_sq += diff * diff;
        }
        double dist = sqrt(dist_sq);

        if (min_dist < 0 || dist < min_dist) {
            min_dist = dist;
            nhan_tot_nhat = mau.y;
        }
    }
    return {nhan_tot_nhat, min_dist};
}

int main() {
    // Tập mẫu Iris tiêu biểu để test theo đề
    vector<Mau> D = {
        {{1.4, 0.2}, "Setosa"},
        {{1.4, 0.2}, "Setosa"},
        {{1.3, 0.2}, "Setosa"},
        {{4.7, 1.4}, "Versicolor"},
        {{4.5, 1.5}, "Versicolor"},
        {{4.9, 1.5}, "Versicolor"},
        {{6.0, 2.5}, "Virginica"},
        {{5.1, 1.9}, "Virginica"}
    };

    string line;
    if (getline(cin, line)) {
        vector<double> q = parse_numbers(line);
        if (!q.empty()) {
            auto res = lang_gieng_gan_nhat(q, D);
            cout << res.first << " " << res.second << endl;
        }
    }
    return 0;
}