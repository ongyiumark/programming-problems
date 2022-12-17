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
    
    vi ar(3);
    for (int &x : ar) cin >> x;
    sort(ar.begin(), ar.end());

    int a = ar[1]-ar[0];
    int b = ar[2]-ar[1];
    if (a == b) cout << ar[2] + a;
    else if (a > b) cout << ar[0] + a/2;
    else cout << ar[1] +b/2;

    cout << "\n";
    return 0;
}