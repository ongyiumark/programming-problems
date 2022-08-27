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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    int p[n];
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p, p+n);
    int total =  0;
    for (int i = 0; i <= n/2; i++) total += p[i]/2;
    for (int i = n/2+1; i < n; i++) total += p[i];

    cout << total << endl;
    return 0;
}