#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        string s; cin >> s;
        vector<array<int, 3>> pref = {{0,0,0}};
        int l = s.size();
        for (char& x : s) {
            auto [a, b, c] = pref.back();
            if (x == 'R') ++a;
            else if (x == 'P') ++b;
            else ++c;
            pref.push_back({a, b, c});
        }
        
        vector<pair<int,int>> ans;
        for (int k = 2; k < l+1; ++k) {
            int temp = 0;
            for (int pos = 0; pos < s.size(); pos += k) {
                int a = pref[min(pos+k, l)][0] - pref[pos][0];
                int b = pref[min(pos+k, l)][1] - pref[pos][1];
                int c = pref[min(pos+k, l)][2] - pref[pos][2];
                temp += max({a, b, c});
            }
            ans.push_back({temp, k});
        }
        sort(ans.rbegin(), ans.rend());
        cout << ans[0].second << endl;
    }

    return 0;
}
