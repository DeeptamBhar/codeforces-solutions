#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Block {
    int color;
    int count;
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<Block> blocks;
    for (int i = 0; i < n; ++i) {
        if (blocks.empty() || blocks.back().color != a[i]) {
            blocks.push_back({a[i], 1});
        } else {
            blocks.back().count++;
        }
    }

    int k = blocks.size();
    
    if (k == 1) {
        cout << 1 << "\n";
        return;
    }

    int max_add = 0;

    for (int i = 0; i < k; ++i) {
        if (blocks[i].count >= 2) {
            if (i + 1 < k && blocks[i + 1].count >= 2) {
                max_add = max(max_add, 2);
            }
            if (i < k - 1) {
                if (i + 1 == k - 1 || blocks[i + 2].color != blocks[i].color) {
                    max_add = max(max_add, 1);
                }
            }
            if (i > 0) {
                if (i - 1 == 0 || blocks[i - 2].color != blocks[i].color) {
                    max_add = max(max_add, 1);
                }
            }
        }
    }

    cout << k + max_add << "\n";
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