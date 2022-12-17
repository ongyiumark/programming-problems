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
    
    string t, p;
    getline(cin, t);
    getline(cin, p);

    int pos = t.find(p, 0);
    if (pos == -1) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> res;
    do {
        res.push_back(pos);
    }
    while ((pos = t.find(p, pos+1)) != -1);

    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i];
        if (i+1 >= (int)res.size()) cout << "\n";
        else cout << " ";
    }

    return 0;
}