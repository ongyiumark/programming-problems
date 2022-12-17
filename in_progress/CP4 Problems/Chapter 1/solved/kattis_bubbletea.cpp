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
    vi tea(n);
    for (int &x : tea) cin >> x;

    int m; cin >> m;
    vi top(m);
    for (int &x : top) cin >> x;

    int cheap = INF;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        while(k--) {
            int j; cin >> j;
            j--;
            cheap = min(cheap, tea[i]+top[j]);
        }
    }

    int x; cin >> x;
    cout << max(x/cheap-1, 0) << "\n";

    
    return 0;
}