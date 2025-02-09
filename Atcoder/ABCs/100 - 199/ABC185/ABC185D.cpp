#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;
    vector<int> a(m);
    for (int &x : a) cin >> x;
    a.push_back(0); a.push_back(n+1);
    sort(a.begin(), a.end());

    int lo = INF;
    for (int i = 0; i < m+1; i++) {
        if (a[i+1]-a[i]-1 <= 0) continue;
        lo = min(a[i+1]-a[i]-1, lo);
    }

    int ans = 0;
    for (int i = 0; i < m+1; i++) {
        if (a[i+1]-a[i]-1 <= 0) continue;
        int d = a[i+1]-a[i]-1;
        ans += (d+lo-1)/lo;
    }

    cout << ans << "\n";


    return 0;
}