/*
    Keep moving from t to u while the last character in t is smaller than any character in s.
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string s; cin >> s;
    int n = s.size();
    int cnt[26][n];
    memset(cnt, 0, sizeof cnt);
    for (int j = 0; j < 26; j++) {
        for (int i = n-1; i >= 0; i--) {
            char ch = 'a'+j;
            if (ch == s[i]) cnt[j][i]++;
            if (i < n-1) cnt[j][i] += cnt[j][i+1];
        }
    }
    
    stack<char> st;
    int idx = 0;
    int curr = 0;
    queue<char> ans;
    while(idx < n){
        while(cnt[curr][idx] == 0) {
            curr++;
        }
        while(!st.empty() && st.top()-'a' <= curr) {
            ans.push(st.top());
            st.pop();
        }
        if (curr == s[idx]-'a') {
            ans.push(s[idx]);
        }
        else {
            st.push(s[idx]);
        }
        idx++;
    }
    while(!st.empty()) {
        ans.push(st.top());
        st.pop();
    }
    while(!ans.empty()) {
        cout << ans.front();
        ans.pop();
    }
    cout << endl;

} 