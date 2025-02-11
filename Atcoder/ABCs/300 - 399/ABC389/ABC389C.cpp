#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int q; cin >> q;
    deque<ll> lengths, heads;
    ll tracker = 0;
    while (q--) {
        int t; cin >> t;
        if (t == 1) {
            ll l; cin >> l;
            if (lengths.empty()) heads.push_back(0);
            else heads.push_back(heads.back()+lengths.back());
            lengths.push_back(l);
        }
        else if (t == 2) {
            tracker += lengths.front();
            lengths.pop_front();
            heads.pop_front();
        }
        else {
            int k; cin >> k;
            cout << heads[k-1]-tracker << "\n";
        }
    }
    return 0;
}