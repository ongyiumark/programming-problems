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
    
    int n;
    int c = 0;
    while(cin >> n, n) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x) res++;
            else res--;
        }
        printf("Case %d: %d\n", ++c, res);
    }
    return 0;
}