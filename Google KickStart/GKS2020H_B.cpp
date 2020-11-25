#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll fastpow(ll b, ll e){
    ll ans = 1;
    while(e > 0) {
        if (e&1) ans *= b;
        b *= b;
        e >>= 1;
    }
    return ans;
}

// Number of ways with the original number of digits.
ll f(string s, bool is_odd){
    int n = s.size();
    if (n == 0) return 0;

    ll ans = 0;
    ll now = s[0]-'0';
    if (is_odd){
        if (now % 2 == 1) {
            ans += (now-1)/2 * fastpow(5, n-1);
            if (n-1 > 0) ans += f(s.substr(1), !is_odd);
            else ans++;
        }
        else ans += (now+1)/2 * fastpow(5, n-1);
    }
    else {
        if (now % 2 == 0){
            ans += (now/2) * fastpow(5, n-1);
            if (n-1 > 0) ans += f(s.substr(1), !is_odd);
            else ans++;
        }
        else ans += (now/2+1) * fastpow(5, n-1);
    }
    return ans;
}

// Add the lower number of digits.
ll g(string s){
    int n = s.size();
    return f(s, 1) + (fastpow(5, n)-1)/4 -1;
}

void testcase(){
    ll l, r; 
    cin >> l >> r;
    cout << g(to_string(r))-g(to_string(l-1)) << endl;
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
