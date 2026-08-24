#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element {
    int val;
    int type; 
};

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> a(x), b(y);
    for(int i = 0; i < x; ++i) cin >> a[i];
    for(int i = 0; i < y; ++i) cin >> b[i];

    vector<Element> elements;
    int i = 0, j = 0;
    
    while (i < x && j < y) {
        if (a[i] == b[j]) {
            elements.push_back({a[i], 3});
            i++; j++;
        } else if (a[i] < b[j]) {
            elements.push_back({a[i], 1});
            i++;
        } else {
            elements.push_back({b[j], 2});
            j++;
        }
    }
    
    while (i < x) {
        elements.push_back({a[i], 1});
        i++;
    }
    while (j < y) {
        elements.push_back({b[j], 2});
        j++;
    }

    reverse(elements.begin(), elements.end());

    long long ans = 0;
    int count_a = 0;
    int count_b = 0;
    int total = 0;
    int max_total = n + m - 1;

    for (const auto& el : elements) {
        if (total == max_total) break; 

        if (el.type == 1) {
            if (count_a < n) {
                count_a++;
                total++;
                ans += el.val;
            }
        } else if (el.type == 2) {
            if (count_b < m) {
                count_b++;
                total++;
                ans += el.val;
            }
        } else { 
            total++;
            ans += el.val;
        }
    }

    cout << ans << "\n";
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