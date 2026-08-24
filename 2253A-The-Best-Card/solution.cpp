#include <iostream>

using namespace std;

bool is_prime(int k) {
    if (k < 2) return false;
    for (int i = 2; i * i <= k; ++i) {
        if (k % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            int n;
            cin >> n;
            
            if (is_prime(n + 1)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}