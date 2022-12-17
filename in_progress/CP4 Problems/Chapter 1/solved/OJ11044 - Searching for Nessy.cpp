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
    
    int TC; cin >> TC;
    while(TC--) {
        int n, m; cin >> n >> m;
        cout << (2 + (n-6)/3)*(2 + (m-6)/3) << "\n";
    }
    
    return 0;
}