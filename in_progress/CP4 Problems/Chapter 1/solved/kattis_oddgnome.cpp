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

    int n; cin >> n;
    while(n--) {
        int g; cin >> g;
        vi ar(g);
        for (int &x : ar) cin >> x;
        int ans = 0;
        for (int i = 1; i < g-1; i++) {
            if (ar[i-1] < ar[i+1] && (ar[i] >= max(ar[i-1], ar[i+1]) || ar[i] <= min(ar[i-1], ar[i+1]))) {
                ans = i+1;
            }
        }
        cout << ans << "\n";
    }
    
    
    return 0;
}