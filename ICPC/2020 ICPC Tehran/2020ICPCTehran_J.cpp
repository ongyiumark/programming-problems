#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, L; cin >> n >> L;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    sort(x.begin(), x.end());

    int total = 0;
    int idx = 0;
    while (idx < n) {
        int lo = idx;
        int hi = n-1;
        int ans = n-1;

        while (lo <= hi) {
            int mid = hi - (hi-lo)/2;
            if (x[idx] + L > x[mid]) {
                ans = mid;
                lo = mid+1;
            } 
            else hi = mid-1;
        }
        total += ans-idx;
        idx = ans+1;
    }
    cout << total << "\n";

    return 0;
}