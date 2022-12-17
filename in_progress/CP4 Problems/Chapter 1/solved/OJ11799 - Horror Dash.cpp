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
    int c = 0;
    while(t--) {
        int n; cin >> n;
        vi ar(n);
        int hi = 0;
        for (int &x : ar) {
            cin >> x;
            hi = max(hi, x);
        }

        printf("Case %d: %d\n", ++c, hi);
    }
    
    return 0;
}