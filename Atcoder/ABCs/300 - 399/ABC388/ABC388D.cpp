#include <bits/stdc++.h>

using namespace std;

const int N = 2e6+5;
struct FenwickTree {
    vector<int> p;
    FenwickTree(int n) : p(n+1) {}
    void update(int i, int x) {
        for (; i < p.size(); i += (i&-i))
            p[i] += x;
    }

    int query(int i) {
        int total = 0;
        for (; i > 0; i -= (i&-i))
            total += p[i];
        return total;
    }
} ft(N);

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int &x : a) cin >> x;

    b[0] = a[0];
    // mapping 0-M to 1-(M+1) because ft is 1-indexed
    ft.update(a[0]+1, 1);
    for (int i = 1; i < n; i++) {
        // count x >= i for x in ft
        int count = ft.query(N)-ft.query(i);
        b[i] = a[i]+i+count;
        ft.update(b[i]+1, 1);
    }

    for (int &x : b) x = max(0, x-(n-1));
    for (int i = 0; i < n; i++) {
        cout << b[i] << " \n"[i == n-1];
    }

    return false;
}