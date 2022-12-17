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

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int hi = -INF;

        int res = -INF;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (i > 0) {
                res = max(res, hi - x);
            }
            hi = max(hi, x);
        }
        cout << res << "\n";
    }
    
    
    return 0;
}