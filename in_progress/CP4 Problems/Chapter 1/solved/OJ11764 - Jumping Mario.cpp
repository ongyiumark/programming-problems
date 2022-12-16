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
        int n; cin >> n;
        vi ar(n);
        for (int &v : ar) cin >> v;

        int lo = 0, hi = 0;
        for (int i = 1; i < n; i++) {
            if (ar[i] > ar[i-1]) hi++;
            else if (ar[i] < ar[i-1]) lo++;
        }

        printf("Case %d: %d %d\n", c, hi, lo);
    }
    return 0;
}