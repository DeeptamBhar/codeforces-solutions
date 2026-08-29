#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> cnt(m + 1, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a <= m) {
            cnt[a]++;
        }
    }
    
    vector<int> pref(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        pref[i] = pref[i - 1] + cnt[i];
    }
    
    int K_max = min(m, 20);
    vector<long long> ans(m + 1, 0);
    
    for (int k = 1; k <= K_max; k++) {
        long long M = 1LL << k;
        long long max_yield = 0;
        
        for (int V = 1; V <= m; V++) {
            long long current_yield = 0;
            
            for (int P = 1; P * V <= m; P++) {
                int L_exact = P * V;
                long long c_exact = cnt[L_exact];
                
                int L_more_start = P * V + 1;
                int L_more_end = min(m, (P + 1) * V - 1);
                long long c_more = 0;
                
                if (L_more_start <= L_more_end) {
                    c_more = pref[L_more_end] - pref[L_more_start - 1];
                }
                
                if (c_exact > 0) {
                    if (P <= M) {
                        current_yield += c_exact * P;
                    } else {
                        current_yield += c_exact * (M - 1);
                    }
                }
                
                if (c_more > 0) {
                    if (P < M) {
                        current_yield += c_more * P;
                    } else {
                        current_yield += c_more * (M - 1);
                    }
                }
            }
            max_yield = max(max_yield, current_yield);
        }
        ans[k] = max_yield;
    }
    
    for (int k = K_max + 1; k <= m; k++) {
        ans[k] = ans[K_max];
    }
    
    for (int k = 1; k <= m; k++) {
        cout << ans[k] << (k == m ? "" : " ");
    }
    cout << "\n";
}

int main() {
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