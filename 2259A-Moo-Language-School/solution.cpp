#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    int cost = 0;
    // Jump by k to check each farm block
    for (int i = 0; i < n; i += k) {
        bool all_ones = true;
        for (int j = 0; j < k; ++j) {
            if (s[i + j] == '0') {
                all_ones = false;
                break;
            }
        }
        // If the entire block is '1's, we must pay the penalty
        if (all_ones) {
            cost++;
        }
    }
    cout << cost << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}