/*
    Note that v_0 + at = v
    We are interested in 
        d = (1/2)*a*(2*t)^2 + v_0*(2*t) 
          = 2*a*t^2 + 2*v_0*t
          = 2*t*(a*t + v_0)
          = 2*t*v
*/
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

    int v, t;
    while (cin >> v >> t) {
        cout << 2*t*v << "\n";
    }

    return 0;
}