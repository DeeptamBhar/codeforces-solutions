#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long n, x, y, z;
    cin >> n >> x >> y >> z;

    // Option 1: Nikita does not use AI
    long long h1 = (n + (x + y) - 1) / (x + y);

    // Option 2: Nikita uses AI
    long long h2;
    if (n <= x * z) {
        // Project finishes while Nikita is still setting up the AI
        h2 = (n + x - 1) / x;
    } else {
        // Project continues after the AI is set up
        long long remaining_lines = n - x * z;
        long long combined_speed = x + 10 * y;
        
        h2 = z + (remaining_lines + combined_speed - 1) / combined_speed;
    }

    // Output the minimum of both strategies
    cout << min(h1, h2) << "\n";
}

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}