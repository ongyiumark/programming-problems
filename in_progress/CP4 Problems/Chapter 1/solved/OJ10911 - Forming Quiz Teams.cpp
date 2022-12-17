/*
    DP with bitmask. 
    DP state is the matching status of the students. When two students i and j are matched, we turn on the ith and jth bit.
*/
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

const int N = 8;
vector<ld> memo(1<<(2*N));

vector<string> s(2*N);
vi x(2*N), y(2*N);

ld dist(int i, int j) {
    return sqrtl((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
}

ld solve(int mask, int n) {
    if (memo[mask] != -1) return memo[mask];
    ld &res = memo[mask];
    if (mask == 0) return 0;

    res = 1e18;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (mask&(1<<i) && mask&(1<<j)) {
                int nmask = mask^(1<<i)^(1<<j);
                res = min(res, solve(nmask, n)+dist(i,j));
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; 
    int t = 0;
    cout << fixed << setprecision(2);
    while(cin >> n) {
        if (n == 0) break;
        t++;

        for (int i = 0; i < 2*n; i++) {
            cin >> s[i] >> x[i] >> y[i];
        }

        vector<ld>(1<<(2*N), -1).swap(memo);

        cout << "Case " << t << ": " << solve((1<<(2*n)) - 1, 2*n) << endl;
    }
    return 0;
}