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

    int m; char p; string res;
    int penalty[26];
    bool solved[26];
    memset(penalty, 0, sizeof penalty);
    memset(solved, 0, sizeof solved);

    int num = 0;
    int ans = 0;
    while(cin >> m, m != -1) {
        cin >> p >> res;
        if (res == "wrong") penalty[p-'A'] += 20;
        else if (!solved[p-'A']) {
            ans += m + penalty[p-'A'];
            solved[p-'A'] = 1;
            num++;
        }
    }

    cout << num << " " << ans << "\n";
    
    
    return 0;
}