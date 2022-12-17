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
    while(t--) {
        int n; cin >> n;
        int p = 0;
        vector<string> ar(n);

        cin.ignore();
        for (int i = 0; i < n; i++) {
            string s;
            getline(cin, s);

            stringstream is(s);
            string tmp;
            is >> tmp;
            if (tmp == "SAME") {
                is >> tmp >> tmp;
                int idx = stoi(tmp);
                ar[i] = ar[idx-1];
            }
            else ar[i] = tmp;
        
            if (ar[i] == "LEFT") p--;
            else p++;
        }

        cout << p << "\n";
    }
    
    return 0;
}