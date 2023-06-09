#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const int INF = 1e9;
const ll INFLL = 4e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    vector<string> pat = {"Alice", "Bob", "Cindy"};

    vector<string> ans;
    for (string t : pat) {
        bool val = 1;
        for (int i = 0; i < s.size() && i < t.size(); i++) {
            if (s[i] == '.') continue;
            val &= (s[i] == t[i]);
        }

        if (val) ans.push_back(t);
    }

    if (ans.size() == 1) cout << ans[0] << "\n";
    else if (ans.size() == 0) cout << "SOMETHING'S WRONG\n";
    else cout << "CAN'T TELL\n";
    
    return 0;
}