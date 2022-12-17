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
    int total = 0;
    while(t--) {
        ld l, w, d, m; cin >> l >> w >> d >> m;
        bool valid = ((l <= 56 && w <= 45 && d <= 25 || l+w+d <= 125) && m <= 7);
        cout << valid << "\n";
        total += valid;
    }

    cout << total << "\n";
    
    return 0;
}