/*
    Add all positive evens.
    Add all positive odds.
    Remove 1 positive odd or add 1 negative odd.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n; 
    vector<int> a(n);
    vector<int> odds;
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i]%2 != 0) odds.push_back(a[i]);
        else {
            if (a[i] > 0) ans += a[i];
        }
    }
    
    int m = odds.size();
    sort(odds.begin(), odds.end(), greater<int>());
    for (int i = 1; i < m; i++) {
        odds[i] += odds[i-1];
    }
    
    int hi = -1e9;
    for (int i = 0; i < m; i += 2) hi = max(hi, odds[i]);
    cout << hi + ans << endl;
    

} 