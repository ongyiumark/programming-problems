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

    int TC;
    cin >> TC;
    while(TC--) {
        ll n; cin >> n;
        ll lo = 0;
        ll hi = 2e9;
        ll ans = 0;
        while(lo <= hi) {
            ll mid = hi - (hi-lo)/2;
            if ((mid * (mid+1)/2) <= n) {
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        cout << ans << "\n";
    }
    return 0;
}