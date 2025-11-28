#include <bits/stdc++.h>

using namespace std;

void testcase() {
    int n; cin >> n;
    vector<int> s(n);
    for (int &x : s) cin >> x;
    
    sort(s.begin()+1, s.end()-1);
    
    vector<int> result;
    result.emplace_back(s[0]);
    int idx = 1;

    bool valid = true;
    while (idx < n-1 && 2*result.back() < s[n-1]) {
        int curr = result.back();
        // look for largest x such that x <= 2*curr in [idx, n]
        int lo = idx;
        int hi = n-2;
        int ans = n-1;

        while (lo <= hi) {
            int mid = hi - (hi-lo)/2;
            if (s[mid] <= 2*curr) {
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }

        if (ans < n-1) result.emplace_back(s[ans]);
        else valid = false;
        idx = ans+1;
    }
    result.emplace_back(s[n-1]);
    
    for (int i=1; i < (int)result.size(); i++) {
        valid &= (2*result[i-1] >= result[i]);
    }


    if (!valid) cout << -1 << "\n";
    else cout << result.size() << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        testcase();
    }
    return 0;
}