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

    int s, n; cin >> s >> n;
    int a[n]; 
    for (int i = 0; i < n; i++) cin >> a[i];

    int total = 0;
    for (int i = 0; i < n-1; i++) total += (a[i+1]-a[i]-2)/2;
    
    total += (a[0]-a[n-1]+s-2)/2;
    cout << total << endl;
    return 0;
}