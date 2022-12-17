#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const ld EPS = 1e-9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int l, r; cin >> l >> r;
    if (l == r && l == 0) {
        cout << "Not a moose" << "\n";
        return 0;
    }

    cout << ((l==r) ? "Even " : "Odd ") << max(l,r)*2 << "\n";
    return 0;
}