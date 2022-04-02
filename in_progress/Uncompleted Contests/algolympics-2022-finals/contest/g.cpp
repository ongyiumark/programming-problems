#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;
 
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int N = 1e5+5;
bool words[26][26];
ll dp[51][26][26];
ll ans[51][26][26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    memset(words, 0, sizeof words);
    ll n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;

        int sz = s.size();
        words[s[0]-'a'][s[sz-1]-'a'] = 1;
    }

    for (int k = 0; k <= 50; k++){
        for (int l = 0; l < 26; l++) {
            for (int r = 0; r < 26; r++){
                dp[k][l][r] = -1e18;
                ans[k][l][r] = -1e18;
            }
        }
    }


    for (int l = 0; l < 26; l++){
        for (int r = 0; r < 26; r++){
            if (words[l][r]) dp[0][l][r] = 0;
        }
    }
    for (int k = 1; k <= 50; k++){
        for (int a = 0; a < 26; a++){
            for (int b = 0; b < 26; b++){
                for (int c = 0; c < 26; c++){
                    for (int d = 0; d < 26; d++){
                        dp[k][a][d] = max(dp[k][a][d], dp[k-1][a][b]+dp[k-1][c][d]+abs(b-c));
                    }
                }
            }
        }
    }
    if (m == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> bits;
    for (ll k = 50; k >= 0; k--){
        if ((1LL << k)&m) {
            bits.push_back(k);
        }
    }

    for (int l = 0; l < 26; l++){
        for (int r = 0; r < 26; r++){
            ans[0][l][r] = dp[bits[0]][l][r];
        }
    }
    for (int i = 1; i < (int)bits.size(); i++){
        for (int a = 0; a < 26; a++){
            for (int b = 0; b < 26; b++){
                for (int c = 0; c < 26; c++){
                    for (int d = 0; d < 26; d++){
                        ans[i][a][d] = max(ans[i][a][d],ans[i-1][a][b]+dp[bits[i]][c][d]+abs(b-c));
                    }
                }
            }
        }
    }

    int bsz = bits.size();
    ll bans = 0;
    for (int l = 0; l < 26; l++){
        for (int r = 0; r < 26; r++){
            bans = max(bans, ans[bsz-1][l][r]);
        }
    }
    cout << bans << endl;

    
    return 0;
}
