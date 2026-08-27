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

double kc_euclid(const vector<double>& u, const vector<double>& v) {
    double sum = 0.0;
    for (size_t i = 0; i < u.size(); i++) {
        double diff = u[i] - v[i];
        sum += diff * diff;
    }
    return sqrt(sum);
}

double kc_manhattan(const vector<double>& u, const vector<double>& v) {
    double sum = 0.0;
    for (size_t i = 0; i < u.size(); i++) {
        sum += abs(u[i] - v[i]);
    }
    return sum;
}

vector<Mau> doc_du_lieu(const string& ten_tep) {
    vector<Mau> D;
    ifstream file(ten_tep);
    
    if (!file.is_open()) {
        return {
            {{5.1, 3.5, 1.4, 0.2}, "Setosa"},
            {{4.9, 3.2, 1.4, 0.2}, "Setosa"},
            {{4.7, 3.2, 1.3, 0.2}, "Setosa"},
            {{7.0, 3.2, 4.7, 1.4}, "Versicolor"},
            {{6.4, 3.2, 4.5, 1.5}, "Versicolor"},
            {{6.5, 2.8, 4.6, 1.5}, "Versicolor"},
            {{6.3, 3.3, 6.0, 2.5}, "Virginica"},
            {{5.8, 2.7, 5.1, 1.9}, "Virginica"},
            {{6.5, 3.0, 5.8, 2.2}, "Virginica"}
        };
    }

    int n, d;
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

pair<string, double> lang_gieng_gan_nhat(const vector<double>& q, const vector<Mau>& D, double (*khoang_cach)(const vector<double>&, const vector<double>&)) {
    string nhan_tot_nhat = "";
    double min_dist = -1.0;

    for (const auto& mau : D) {
        if (mau.x.size() != q.size()) continue;
        double dist = khoang_cach(q, mau.x);

        if (min_dist < 0 || dist < min_dist) {
            min_dist = dist;
            nhan_tot_nhat = mau.y;
        }
    }
    return {nhan_tot_nhat, min_dist};
}

int main() {
    vector<Mau> D = doc_du_lieu("data.txt");

    string line;
    if (getline(cin, line)) {
        vector<double> q = parse_numbers(line);
        if (!q.empty()) {
            auto res_euclid = lang_gieng_gan_nhat(q, D, kc_euclid);
            auto res_manhattan = lang_gieng_gan_nhat(q, D, kc_manhattan);

            cout << fixed << setprecision(4);
            cout << "Euclid: " << res_euclid.first << " (" << res_euclid.second << ")" << endl;
            cout << "Manhattan: " << res_manhattan.first << " (" << res_manhattan.second << ")" << endl;
        }
    }
    return 0;
}