#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> p(n);
    for (int &x : p) cin >> x;

    ll total = 0;
    for (int i = 1; i < n; i++) {
        if (p[i-1] >= p[i]) continue;
        total += p[i]-p[i-1];
        p[i] -= p[i]-p[i-1];
    }
    cout << total << "\n";

    return 0;
}