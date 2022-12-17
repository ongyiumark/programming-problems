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
    
    int L, x; cin >> L >> x;
    int cnt = 0;
    int ans = 0;
    while(x--) {
        string s; int n;
        cin >> s >> n;
        if (s == "enter") {
            if (cnt + n > L) ans++;
            else cnt += n;
        }
        else cnt -= n;
    } 

    cout << ans << "\n";
    
    return 0;
}