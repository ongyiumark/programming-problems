#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void testcase(){
    int n, m; cin >> n >> m;
    if (n > m) swap(n,m);
    if (n == 1 && m == 1) {
        cout << 0 << "\n";
    }
    else if (n == 1) {
        cout << 1 << "\n";
    }
    else cout << 2 << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        testcase();
    }
    return 0;
}