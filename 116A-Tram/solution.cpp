#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int current_passengers = 0;
    int max_capacity = 0;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        
        current_passengers -= a;
        current_passengers += b;

        if (current_passengers > max_capacity) {
            max_capacity = current_passengers;
        }
    }

    cout << max_capacity << "\n";

    return 0;
}