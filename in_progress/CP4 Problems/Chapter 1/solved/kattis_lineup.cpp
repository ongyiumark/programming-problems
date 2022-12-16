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

    int n; cin >> n;
    vector<string> ar(n);
    for (string &s : ar) cin >> s;

    bool isIncrease = 1;
    bool isDecrease = 1;
    for (int i = 1; i < n; i++) {
        isIncrease &= (ar[i-1] < ar[i]);
        isDecrease &= (ar[i-1] > ar[i]);
    }

    if (isIncrease) cout << "INCREASING";
    else if (isDecrease) cout << "DECREASING";
    else cout << "NEITHER";
    cout << "\n";
    
    return 0;
}