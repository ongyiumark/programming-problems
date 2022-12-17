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

int score(string s) {
    int res = 0;
    for (char &ch : s) {
        if (isalpha(ch)) {
            ch = tolower(ch);
            res += ch-'a'+1;
        }
    }
    return res%9 == 0 ?  9 : res%9;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s, t;
    while(getline(cin, s), getline(cin, t)) {
        int sscore = score(s);
        int tscore = score(t);
        if (sscore > tscore) swap(sscore, tscore);

        cout << fixed << setprecision(2) << (ld)sscore/(ld)tscore*100 << " %\n"; 
    }
    
    return 0;
}