#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ones;
    int first_minus_one = -1;
    int last_minus_one = -1;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            ones.push_back(i);
        }
        if (a[i] == -1) {
            if (first_minus_one == -1) first_minus_one = i;
            last_minus_one = i;
        }
    }
    
    int best_L = -1, best_R = -1;
    int max_dist = 0;
    
    if (ones.empty()) {
        if (first_minus_one != -1) {
            best_L = first_minus_one;
            best_R = last_minus_one;
        }
    } else {
        for (size_t i = 0; i + 1 < ones.size(); ++i) {
            int dist = ones[i+1] - ones[i] + 1;
            if (dist > max_dist) {
                max_dist = dist;
                best_L = ones[i];
                best_R = ones[i+1];
            }
        }
        
        if (first_minus_one != -1 && first_minus_one < ones.front()) {
            int dist = ones.front() - first_minus_one + 1;
            if (dist > max_dist) {
                max_dist = dist;
                best_L = first_minus_one;
                best_R = ones.front();
            }
        }
        
        if (last_minus_one != -1 && last_minus_one > ones.back()) {
            int dist = last_minus_one - ones.back() + 1;
            if (dist > max_dist) {
                max_dist = dist;
                best_L = ones.back();
                best_R = last_minus_one;
            }
        }
    }
    
    if (best_L != -1) {
        a[best_L] = 1;
        a[best_R] = 1;
    }
    
    for (int i = 0; i < n; ++i) {
        if (a[i] == -1) {
            a[i] = 0;
        }
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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