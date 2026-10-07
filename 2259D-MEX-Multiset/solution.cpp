#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> count;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        count[a[i]]++;
    }
    
    if (count[0] == 1) {
        cout << "NO\n";
        return;
    }
    
    int k = 0;
    while (count[k] >= 2) {
        k++;
    }
    
    cout << "YES\n";
    set<int> given_A, given_B;
    string res = "";
    
    for (int x : a) {
        if (x < k) {
            if (given_A.find(x) == given_A.end()) {
                res += 'A';
                given_A.insert(x);
            } else if (given_B.find(x) == given_B.end()) {
                res += 'B';
                given_B.insert(x);
            } else {
                res += 'A';
            }
        } else {
            res += 'C';
        }
    }
    
    cout << res << "\n";
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