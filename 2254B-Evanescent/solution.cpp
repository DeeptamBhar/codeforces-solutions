#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int initial_len = 1;
    for (int i=1; i<n; ++i){
        if(s[i]!=s[i-1]){
            initial_len++;
        }
    }

    int max_reduction = 0;
    for (int i=1; i<n-1; ++i){
        int change = 0;
        if (s[i]!=s[i-1]&& s[i]!=s[i+1]){
            if(s[i-1]==s[i+1]){
                change = -2;
            }
            else{change = -1;}
        }
        max_reduction = min(max_reduction, change);
    }
    cout << initial_len + max_reduction << "\n";
}


int main() {
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}

