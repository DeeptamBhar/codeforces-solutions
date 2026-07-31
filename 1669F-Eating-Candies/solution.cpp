#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    if (n == 1) {
        cout << 0 << "\n";
        return;
    }

    int left = 0, right = n - 1;
    int sum_a = w[left], sum_b = w[right];
    int max_candies = 0;

    while (left < right) {
        if (sum_a == sum_b) {
            max_candies = max(max_candies, left + 1 + n - right);
            left++;
            sum_a += w[left];
        } else if (sum_a < sum_b) {
            left++;
            sum_a += w[left];
        } else {
            right--;
            sum_b += w[right];
        }
    }
    
    cout << max_candies << "\n";
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