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
    while(1) {
        cin >> s;
        if (s == "#") break;

        string lang;
        if (s == "HELLO") lang = "ENGLISH";
        else if (s == "HOLA") lang = "SPANISH";
        else if (s == "HALLO") lang = "GERMAN";
        else if (s == "BONJOUR") lang = "FRENCH";
        else if (s == "CIAO") lang = "ITALIAN";
        else if (s == "ZDRAVSTVUJTE") lang = "RUSSIAN";
        else lang = "UNKNOWN";

        printf("Case %d: %s\n", ++c, lang.c_str());
    }
    
    return 0;
}