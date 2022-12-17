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
    int c = 0;
    while(t--) {
        vector<string> web[101];
        for (int i = 0; i < 10; i++) {
            string s; int v; cin >> s >> v;
            web[v].push_back(s);
        }

        int idx = 100;
        while(web[idx].size() == 0) --idx;
        
        cout << "Case #" << ++c << ":\n";
        for (string s : web[idx]) {
            cout << s << "\n";
        }
    }
    
    
    return 0;
}