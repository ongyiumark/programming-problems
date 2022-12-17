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

int score(int x, int y) {
    if (x < y) swap(x, y);
    if (x == 2 && y == 1) return 200;
    if (x == y) return 100+10*x+y;
    return 10*x+y; 
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c, d;
    while(cin >> a >> b >> c >> d, a|b|c|d) {
        int p1 = score(a,b);
        int p2 = score(c,d);
        if (p1 > p2) cout << "Player 1 wins.";
        else if (p1 < p2) cout << "Player 2 wins.";
        else cout << "Tie.";
        cout << "\n";
    }
    
    
    return 0;
}