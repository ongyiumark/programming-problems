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
    
    int n, b, h, w; 
    while(cin >> n >> b >> h >> w) { 
        int res = INF;       
        for (int i = 0; i < h; i++) {
            int p; cin >> p;
            for (int i = 0; i < w; i++) {
                int a; cin >> a;
                if (p*n <= b && a >= n) {
                    res = min(res, p);
                }
            }
        }

        if (res < INF) cout << res*n;
        else cout << "stay home";
        cout << "\n"; 
    }
    return 0;
}