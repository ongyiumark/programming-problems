#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5+1;
ll x[N];
ll y[N];

ll compute(ll t, ll n){
    ll ans = 0;
    for (ll i = 0; i < n; i++){
        ans += abs(x[i]-t-i);
    }
    return ans;
}

void testcase(){
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    sort(y, y+n);
    ll ans = 0;
    for (int i = 0; i < n; i++){
        ans += abs(y[i]-y[n/2]);
    }

    sort(x, x+n);
    ll lo = -2e9;
    ll hi = 2e9;
    while(lo <= hi){
        ll mid = hi - (hi-lo)/2;
        if (compute(mid,n) >= compute(mid+1,n)){
            lo = mid+1;
        }
        else if (compute(mid,n) >= compute(mid-1,n)){
            hi = mid-1;
        }
        else {
            ans += compute(mid,n);
            cout << ans << endl;
            return;
        }
    }

    ans += min(compute(lo, n), compute(hi,n));
    cout << ans << endl;
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
