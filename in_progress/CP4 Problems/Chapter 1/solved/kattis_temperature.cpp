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
    
    int x, y; cin >> x >> y;
    if (y == 1) {
        if (x == 0) cout << "ALL GOOD\n";
        else cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << fixed << setprecision(6) << (ld)(x)/(ld)(1-y) << "\n";

    return 0;
}