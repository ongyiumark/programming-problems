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

int getYear(string s) {
    stringstream is(s);
    string year;
    getline(is, year, '/');
    return stoi(year);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        string name, schoolDate, birthDate;
        int courses;
        cin >> name >> schoolDate >> birthDate >> courses;

        cout << name << " ";
        if (getYear(schoolDate) >= 2010 || getYear(birthDate) >= 1991) cout << "eligible\n";
        else if (courses > 40) cout << "ineligible\n";
        else cout << "coach petitions\n";  
    }
    
    return 0;
}