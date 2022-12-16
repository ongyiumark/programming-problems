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

    vector<string> tokens;
    string t; getline(cin, t);
    // lowercase and replace periods into spaces
    for (char &ch : t) {
        ch = tolower(ch);
        if (ch == '.') ch = ' ';
    }

    // collapse spaces into 1
    string s;
    s += t[0];
    for (int i = 1; i < t.size(); i++) {
        if (t[i-1] == t[i]  && t[i] == ' ') continue;
        s += t[i];
    }

    // tokenize
    stringstream ss(s);
    string token;
    unordered_map<string, int> freq;

    int hi_score = 0;
    string best = "";
    while(getline(ss, token, ' ')) {
        freq[token]++;

        // save best
        if (freq[token] >= hi_score) {
            hi_score = freq[token];
            best = token;
        }
    }

    cout << best << endl;
    return 0;
}