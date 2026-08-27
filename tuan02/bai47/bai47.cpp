#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

struct Mau {
    vector<double> x;
    string y;
};

// Hàm chuẩn hóa chuỗi và bóc tách các số thực (xử lý cả dấu phẩy 4,9 -> 4.9)
vector<double> parse_numbers(string s) {
    for (size_t i = 1; i + 1 < s.length(); i++) {
        if (s[i] == ',' && isdigit(s[i - 1]) && isdigit(s[i + 1])) {
            s[i] = '.';
        }
    }
    for (char& c : s) {
        if (c == '(' || c == ')' || c == ';' || c == ',') c = ' ';
    }
    stringstream ss(s);
    vector<double> nums;
    double val;
    while (ss >> val) nums.push_back(val);
    return nums;
}

vector<Mau> doc_du_lieu(const string& ten_tep, int &d) {
    vector<Mau> D;
    ifstream file(ten_tep);
    
    // Nạp dữ liệu mẫu dự phòng nếu chưa có tệp data.txt
    if (!file.is_open()) {
        d = 4;
        return {
            {{5.1, 3.5, 1.4, 0.2}, "Setosa"},
            {{4.9, 3.0, 1.4, 0.2}, "Setosa"},
            {{4.7, 3.2, 1.3, 0.2}, "Setosa"},
            {{4.6, 3.1, 1.5, 0.2}, "Setosa"},
            {{5.0, 3.6, 1.4, 0.2}, "Setosa"},
            {{7.0, 3.2, 4.7, 1.4}, "Versicolor"},
            {{6.4, 3.2, 4.5, 1.5}, "Versicolor"},
            {{6.9, 3.1, 4.9, 1.5}, "Versicolor"},
            {{5.5, 2.3, 4.0, 1.3}, "Versicolor"},
            {{6.5, 2.8, 4.6, 1.5}, "Versicolor"},
            {{6.3, 3.3, 6.0, 2.5}, "Virginica"},
            {{5.8, 2.7, 5.1, 1.9}, "Virginica"},
            {{7.1, 3.0, 5.9, 2.1}, "Virginica"},
            {{6.3, 2.9, 5.6, 1.8}, "Virginica"},
            {{6.5, 3.0, 5.8, 2.2}, "Virginica"}
        };
    }

    int n;
    if (file >> n >> d) {
        for (int i = 0; i < n; i++) {
            Mau mau;
            mau.x.resize(d);
            for (int j = 0; j < d; j++) {
                file >> mau.x[j];
            }
            file >> mau.y;
            D.push_back(mau);
        }
    }
    file.close();
    return D;
}

pair<string, double> lang_gieng_gan_nhat(const vector<double>& q, const vector<Mau>& D) {
    string nhan_tot_nhat = "";
    double min_dist = -1.0;

    for (const auto& mau : D) {
        if (mau.x.size() != q.size()) continue;
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
    int d = 0;
    vector<Mau> D = doc_du_lieu("data.txt", d);

    string line;
    if (getline(cin, line)) {
        vector<double> q = parse_numbers(line);
        if (!q.empty()) {
            auto res = lang_gieng_gan_nhat(q, D);
            // In kết quả và làm tròn 4 chữ số thập phân
            cout << res.first << " " << fixed << setprecision(4) << res.second << endl;
        }
    }
    return 0;
}