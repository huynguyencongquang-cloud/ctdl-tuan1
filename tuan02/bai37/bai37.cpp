#include <iostream>
#include <vector>

using namespace std;

void dem(const vector<int>& a, int &chan, int &le, int &am) {
    chan = 0;
    le = 0;
    am = 0;
    for (int x : a) {
        if (x < 0) am++;
        if (x % 2 == 0) chan++;
        else le++;
    }
}

int main() {
    int n;
    if (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        int chan, le, am;
        dem(a, chan, le, am);
        cout << chan << " " << le << " " << am << endl;
    }
    return 0;
}