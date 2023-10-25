#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2e18;

const int N_MAX = 105;
const int S_MAX = 105*500;

int memo[N_MAX][S_MAX];
int C[N_MAX];
int total = 0;
int n;

int solve(int i, int S) {
    int &ans = memo[i][S];
    if (ans != -1) return ans;

    if (i == n) return ans = abs(2*S-total);
    return ans = min(solve(i+1, S), solve(i+1, S+C[i]));
}

void testcase() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> C[i];

    memset(memo, -1, sizeof memo);
    total = 0;
    for (int i = 0; i < n; i++) total += C[i];

    cout << solve(0, 0) << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--) testcase();


    return 0;
}