#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

template<typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool factorize(ll x, map<ll,int> &fact) {
    bool isprime = 1;
    for (ll i = 2; i*i <= x; i++) {
        while(x%i == 0) {
            fact[i]++;
            x /= i;
            isprime = 0;
        }
    }
    if (x > 1) fact[x]++; 
    return isprime;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll a, b; cin >> a >> b;
    map<ll, int> facta, factb;
    int statusA = factorize(a, facta); 
    int statusB = factorize(b, factb);
    if (statusA && statusB && a != b) cout << "full credit" << endl;
    else {
        bool partial = 1;
        for (auto it : facta) {
            if (it.second > 1 || (it.second > 0 && factb[it.first] > 0)) partial = 0; 
        }
        for (auto it : factb) {
            if (it.second > 1 || (it.second > 0 && facta[it.first] > 0)) partial = 0; 
        }
        cout << (partial ? "partial credit" : "no credit") << endl; 
    }
    return 0;
}