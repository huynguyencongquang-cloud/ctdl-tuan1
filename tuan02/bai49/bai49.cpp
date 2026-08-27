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

double do_chinh_xac_bo_mot_mau(const vector<Mau>& D, double (*kc)(const vector<double>&, const vector<double>&)) {
    int count_correct = 0;
    int n = D.size();
    if (n == 0) return 0.0;

    for (int i = 0; i < n; i++) {
        string nhan_du_doan = "";
        double min_dist = -1.0;

        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            double dist = kc(D[i].x, D[j].x);
            if (min_dist < 0 || dist < min_dist) {
                min_dist = dist;
                nhan_du_doan = D[j].y;
            }
        }

        if (nhan_du_doan == D[i].y) {
            count_correct++;
        }
    }

    return (double)count_correct / n;
}

vector<Mau> doc_du_lieu(const string& ten_tep) {
    vector<Mau> D;
    ifstream file(ten_tep);
    if (!file.is_open()) return D;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        vector<string> tokens;
        string token;
        while (ss >> token) {
            tokens.push_back(token);
        }
        
        // Nếu là dòng khai báo kích thước (chỉ chứa 2 số) thì bỏ qua
        if (tokens.size() == 2) continue;

        if (tokens.size() >= 2) {
            Mau mau;
            for (size_t i = 0; i < tokens.size() - 1; i++) {
                mau.x.push_back(stod(tokens[i]));
            }
            mau.y = tokens.back();
            D.push_back(mau);
        }
    }
    file.close();
    return D;
}

int main() {
    vector<Mau> D = doc_du_lieu("data.txt");

    double acc_e = do_chinh_xac_bo_mot_mau(D, kc_euclid);
    double acc_m = do_chinh_xac_bo_mot_mau(D, kc_manhattan);

    cout << fixed << setprecision(2);
    cout << "Euclid: " << acc_e * 100 << "%" << endl;
    cout << "Manhattan: " << acc_m * 100 << "%" << endl;

    return 0;
}