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
    for (int c = 1; c <= t; c++) {
        int l, w, h; cin >> l >> w >> h;
        printf("Case %d: %s\n", c, (l <= 20 && w <= 20 && h <= 20) ? "good" : "bad");
    }
    
    return 0;
}