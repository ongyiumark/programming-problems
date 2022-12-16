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
    vi ans(n);
    ans[0] = 1;
    for (int i = 0; i < n-1; i++) {
        int x; cin >> x;
        ans[x+1] = i+2;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i];
        if (i+1 < n) cout << " ";
        else cout << "\n";
    }
    
    
    return 0;
}