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
    int ans = 0;
    if (x > 0) {
        if (y > 0) ans = 1;
        else ans = 4;
    }
    else {
        if (y > 0) ans = 2;
        else ans = 3;
    }

    cout << ans << "\n";
    
    return 0;
}