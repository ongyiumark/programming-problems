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

    string s;
    int c = 0;
    string t = "";
    while(true) {
        getline(cin, s);
        if (s.substr(0,7) == ".......") break;

        if (c > 0) t += " ";
        t += s;
        c++;
    }
    cout << t << "\n";
    
    return 0;
}