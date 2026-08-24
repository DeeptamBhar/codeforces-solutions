#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    vector<int> a_even, a_odd, b_even, b_odd;

    for (int i = 0; i < n; ++i) {
        if (a[i] == '1') {
            if (i % 2 == 0) a_even.push_back(i);
            else a_odd.push_back(i);
        }
        if (b[i] == '1') {
            if (i % 2 == 0) b_even.push_back(i);
            else b_odd.push_back(i);
        }
    }

    if (a_even.size() != b_even.size() || a_odd.size() != b_odd.size()) {
        cout << -1 << "\n";
        return;
    }

    long long total_operations = 0;
    
    for (size_t i = 0; i < a_even.size(); ++i) {
        total_operations += abs(a_even[i] - b_even[i]) / 2;
    }
    
    for (size_t i = 0; i < a_odd.size(); ++i) {
        total_operations += abs(a_odd[i] - b_odd[i]) / 2;
    }

    cout << total_operations << "\n";
}

int main() {
   
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}