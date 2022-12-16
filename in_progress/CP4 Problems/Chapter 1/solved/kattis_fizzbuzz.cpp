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
    
    int x, y, n; cin >>  x >> y >> n;
    for (int i = 1; i <= n; i++) {
        if (i % x == 0) cout << "Fizz";
        if (i % y == 0) cout << "Buzz";
        if (i % x != 0 && i % y != 0) cout << i;
        cout << "\n";
    }
    return 0;
}