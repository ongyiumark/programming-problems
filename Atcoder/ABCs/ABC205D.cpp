#include <iostream>
#include <iomanip>
#include <set>
#include <vector>

using namespace std;
typedef long double ld;
typedef long long ll;

int main(int argc, char *argv[])
{

    ll n, q; cin >> n >> q;
    vector<ll> a(n), k(q);
    for (ll &x : a) cin >> x;
    for (ll &x : k) cin >> x;

    vector<ll> cnt(n);
    for (int i = 0; i < n; i++) cnt[i] = a[i]-i-1;
    for (int i = 0; i < q; i++) {
        ll lo = 0;
        ll hi = n-1;
        ll ans = -1;

        while (lo <= hi) {
            ll mid = hi-(hi-lo)/2;
            if (cnt[mid] < k[i]) {
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }

        if (ans == -1) cout << k[i];
        else cout <<a[ans]+k[i]-cnt[ans];
        cout << '\n';
    }
}