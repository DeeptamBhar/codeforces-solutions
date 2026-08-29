#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<long long> cnt(m + 1, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    vector<long long> S(m + 2, 0);
    for (int i = m; i >= 1; i--) {
        S[i] = S[i + 1] + cnt[i];
    }
    
    long long max_carrots = 0;
    
    for (int V = 1; V <= m; V++) {
        long long current_carrots = S[V];
        
        if (2 * V <= m) {
            current_carrots += cnt[2 * V];
        }
        
        max_carrots = max(max_carrots, current_carrots);
    }
    
    cout << max_carrots << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}