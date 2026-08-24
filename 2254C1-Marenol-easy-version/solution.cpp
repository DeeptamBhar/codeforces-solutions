#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int even_ones_a = 0, odd_ones_a = 0;
    int even_ones_b = 0, odd_ones_b = 0;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            if (a[i] == '1') even_ones_a++;
            if (b[i] == '1') even_ones_b++;
        } else {
            if (a[i] == '1') odd_ones_a++;
            if (b[i] == '1') odd_ones_b++;
        }
    }

    if (even_ones_a == even_ones_b && odd_ones_a == odd_ones_b) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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