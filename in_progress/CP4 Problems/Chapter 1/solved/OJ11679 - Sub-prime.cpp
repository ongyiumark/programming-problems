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
    
    int b, n;
    while(cin >> b >> n, b|n) {
        vi r(b);
        for (int &x : r) cin >> x;
        for (int i = 0; i < n; i++) {
            int d, c, v; cin >> d >> c >> v;
            d--; c--;
            r[d] -= v;
            r[c] += v;
        }
        
        bool valid = 1;
        for (int i = 0; i < b; i++) {
            if (r[i] < 0) valid = 0;
        }

        cout << (valid ? "S" : "N") << "\n";
    }
    return 0;
}