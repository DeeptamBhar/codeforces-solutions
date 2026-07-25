#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> p(n + 1);
    vector<vector<int>> children(n + 1);
    
    // Read tree structure
    for (int i = 2; i <= n; ++i) {
        cin >> p[i];
        children[p[i]].push_back(i);
    }

    // 1. Calculate depths (going forward since p[i] < i guarantees topological order)
    vector<int> depth(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        depth[i] = depth[p[i]] + 1;
    }

    // 2. Calculate maximum depths (going backward propagates max depth to parents)
    vector<int> max_depth = depth;
    for (int i = n; i >= 2; --i) {
        max_depth[p[i]] = max(max_depth[p[i]], max_depth[i]);
    }

    // 3. Base count is N (every vertex represents a distinct guild of size 1 at h=0)
    long long ans = n;
    
    // 4. Add the branch contributions
    for (int i = 1; i <= n; ++i) {
        if (children[i].size() >= 2) {
            int m1 = -1; // Highest max_depth among children
            int m2 = -1; // Second highest max_depth among children
            
            for (int c : children[i]) {
                if (max_depth[c] > m1) {
                    m2 = m1;
                    m1 = max_depth[c];
                } else if (max_depth[c] > m2) {
                    m2 = max_depth[c];
                }
            }
            
            // Add the number of depths where at least 2 children overlap
            ans += (m2 - depth[i]);
        }
    }

    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
