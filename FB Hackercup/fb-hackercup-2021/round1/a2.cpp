#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T,null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;

const ll MOD = 1e9+7;
const int N = 8e5+5;
int nextxo[N];
ll dp[N];

string s;
int n;
ll solve(){
    ll ans = 0;
    int j = 0;
    int cnt = 0;
    while(j < n && s[j] == 'F') j++;
    if (j == n) return cnt;

    bool is_left = (s[j]=='X');
    while(j < n){
        if (is_left){
            while(j < n && s[j] != 'O') {
                j++;
                ans = (ans + cnt)%MOD;
            }
        }
        else {
            while(j < n && s[j] != 'X') {
                j++;
                ans = (ans + cnt)%MOD;
            }
        }
        is_left = !is_left;
        cnt++;
    }
    return ans;
}

void testcase(){
    cin >> n;
    cin >> s;
    int curr = n;
    for(int i = n-1; i >= 0; i--){
        nextxo[i] = curr;
        if (s[i] == 'X' || s[i] == 'O') curr = i;
    }

    dp[0] = solve();
    for (int i = 1; i < n; i++){
        if (nextxo[i-1] == n) dp[i] = (dp[i-1])%MOD;
        else if (s[nextxo[i-1]] == s[i-1] || s[i-1] == 'F') dp[i] = (dp[i-1])%MOD;
        else dp[i] = (dp[i-1]-(n-nextxo[i-1]))%MOD;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++){
        ans = (dp[i]+ans)%MOD;
    }
    cout << (ans+MOD)%MOD << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int x = 1; x <= t; x++){
        cout << "Case #" << x << ": ";
        testcase();
    }
    return 0;
}