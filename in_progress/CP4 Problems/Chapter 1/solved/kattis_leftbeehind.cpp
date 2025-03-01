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

    int x, y;
    while(cin >> x >> y, x | y) {
        if (x+y == 13) cout << "Never speak again.\n";
        else if (y > x) cout << "Left beehind.\n";
        else if (y < x) cout << "To the convention.\n";
        else cout << "Undecided.\n";
    }
    
    
    return 0;
}