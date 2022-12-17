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
    
    string s;
    while(cin >> s, s != "END") {
        if (s == "1") {
            cout << 1 << "\n";
            continue;
        }

        int ans = 2;
        while(s.size() != 1) {
            s = to_string(s.size());
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}