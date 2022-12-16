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
        string s; cin >> s;
        if (s == "P=NP") cout << "skipped\n";
        else {
            stringstream is(s);
            string astr, bstr;
            getline(is, astr, '+');
            getline(is, bstr);

            int a = stoi(astr);
            int b = stoi(bstr);
            
            cout << a + b << "\n";
        }
    }
    
    return 0;
}