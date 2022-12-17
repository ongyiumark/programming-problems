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

    int n, m; cin >> n >> m;
    int d = abs(n-m);
    const char* s = ((d == 1) ? "piece" : "pieces");
    if (n < m) printf("Dr. Chaz will have %d %s of chicken left over!\n", d, s);
    else printf("Dr. Chaz needs %d more %s of chicken!\n", d, s);
    return 0;
}