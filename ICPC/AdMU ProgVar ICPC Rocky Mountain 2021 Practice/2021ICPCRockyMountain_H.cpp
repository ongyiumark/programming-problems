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

const int N = 1e5+5;
int w[N];
int pref[N], diff[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, C; cin >> n >> C;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    memset(pref, 0, sizeof pref);
    for (int i = 1; i <= n; i++) pref[i] = pref[i-1]+w[i];

    vector<ii> windows;
    int s = 1, e = 1;
    windows.push_back({s,e});
    while (s <= n) {
        if (e+1 > n) s++;
        else if (pref[e+1]-pref[s-1] > C) s++;
        else e++;
        windows.push_back({s,e});
    }

    memset(diff, 0, sizeof diff);
    for (auto &[s,e] : windows){
        diff[s]++; diff[e+1]--;
    }

    for (int i = 1; i <= n; i++) {
        diff[i] += diff[i-1];
    }

    for (int i = 1; i <= n; i++) {
        cout << diff[i] << endl;
    }



    return 0;
}