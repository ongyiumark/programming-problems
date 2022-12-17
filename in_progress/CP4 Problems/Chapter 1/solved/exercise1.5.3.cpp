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
    
    string t; getline(cin, t);
    int digits = 0, vowels = 0, consonants = 0;
    string v = "aeiou";
    for (char &ch : t) {
        ch = tolower(ch);
        if (isdigit(ch)) digits += 1;
        else if (isalpha(ch)) {
            if (v.find(ch) != -1) vowels += 1;
            else consonants += 1;
        }
    }
    cout << t << endl;
    printf("There are %d vowels, %d consonants, and %d digits.\n", vowels, consonants, digits);
    return 0;
}