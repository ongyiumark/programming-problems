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
    
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        cout << abs((n*567/9+7492)*235/47 - 498) / 10 % 10 << "\n";
    }
    return 0;
}