#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int c_odd = 0, c_0 = 0, c_2 = 0;
    
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x % 2 != 0) {
            c_odd++;
        } else if (x % 4 == 0) {
            c_0++;
        } else {
            c_2++;
        }
    }
    
    cout << max({c_odd, c_0, c_2}) << "\n";
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