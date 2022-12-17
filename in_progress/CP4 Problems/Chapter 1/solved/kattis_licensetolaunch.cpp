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
    vi ar(n);

    int score = INF;
    int best = 0;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        if (ar[i] < score) {
            score = ar[i];
            best = i;
        }
    }
    cout << best << "\n";
    
    return 0;
}