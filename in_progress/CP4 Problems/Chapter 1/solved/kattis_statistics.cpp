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
    int n;
    int c = 0;

    while(scanf("%d", &n) != EOF){
        vi ar(n);
        int lo = INF;
        int hi = -INF;
        for (int i = 0; i < n; i++) {
            scanf("%d", &ar[i]);
            hi = max(hi, ar[i]);
            lo = min(lo, ar[i]);
        }

        printf("Case %d: %d %d %d\n", ++c, lo, hi, hi-lo);
    }
    
    return 0;
}