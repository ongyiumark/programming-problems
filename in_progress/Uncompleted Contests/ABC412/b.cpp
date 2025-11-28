#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t; cin >> s >> t;
    int s_size = s.size();
    bool valid = true;
    for (int i=2; i<s_size; i++) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            valid &= (t.find(s[i-1]) != string::npos);
        }
    }
    cout << (valid ? "Yes\n" : "No\n");
    return 0;
}