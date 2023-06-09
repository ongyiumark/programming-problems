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

    // (n+2)(n+1)/2 -1
    // (n^2 + 3n + 2)/2 - 1
    // n(n+3)/2

    ll n, q; cin >> n >> q;
    while(q--) {
        ll i; cin >> i;

        ll lo = 0;
        ll hi = n;
        ll ans = n;
        while (lo <= hi) {
            ll mid = hi - (hi-lo)/2;
            if (mid*(mid+3) < 2*i) {
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }

        if (ans >= n) {
            printf("Codemas is already over!\n");
            continue;
        }

        i -= ans*(ans+3)/2;
        ll d = ans+1;
        if (i == 1) {
            string ord = "th";
            if (d%10 == 1 && d%100 != 11) ord = "st";
            if (d%10 == 2 && d%100 != 12) ord = "nd";
            if (d%10 == 3 && d%100 != 13) ord = "rd";
            printf("On the %lld%s day of Codemas, my computer gave to me,\n", d, ord.c_str());
        } 
        else if (i == d+1) {
            if (d == 1) printf("A syntax error on line three!\n");
            else printf("And a syntax error on line three!\n");
        }
        else if (d-i+2 == 5) {
            printf("FIVE! COMPILER! WARNINGS!!!\n");
        }
        else {
            printf("%lld compiler warnings,\n", d-i+2);
        }
    }

    return 0;
}