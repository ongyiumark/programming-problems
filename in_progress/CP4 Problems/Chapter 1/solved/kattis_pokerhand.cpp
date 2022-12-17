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
    
    unordered_map<char, int> um;
    for (int i = 0; i < 5; i++) {
        string s; cin >> s;
        um[s[0]]++;
    }

    int ans = 0;
    for (auto it : um) ans = max(ans, it.second);
    cout << ans << "\n";
    
    return 0;
}