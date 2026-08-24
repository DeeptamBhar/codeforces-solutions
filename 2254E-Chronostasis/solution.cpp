#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    multiset<long long> b_elements;
    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        b_elements.insert(val);
    }
    
    long long current_sum = 0;
    vector<long long> a;
    a.reserve(n);
    
    for (int i = 0; i < n; ++i) {
        long long target = 1 - current_sum;
        auto it = b_elements.lower_bound(target);
        if (it == b_elements.end()) {
            cout << -1 << "\n";
            return;
        }
        long long chosen_b = *it;
        current_sum += chosen_b;
        a.push_back(current_sum);        
        b_elements.erase(it);
    }    
    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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