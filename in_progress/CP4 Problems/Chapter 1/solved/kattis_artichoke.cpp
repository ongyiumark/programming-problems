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

int p, a, b, c, d, n;
ld price(int k) {
    return p*(sin(a*k+b) + cos(c*k + d)+2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    cin >> p >> a >> b >> c >> d >> n;
    ld hi = -INF;
    ld ans = 0;
    for (int i = 1; i <= n; i++) {
        ld pp = price(i);
        hi = max(hi, pp);
        ans = max(hi - pp, ans);
    }
    cout << fixed << setprecision(7) << ans << "\n";
    
    return 0;
}