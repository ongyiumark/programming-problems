#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<ld,ld> ii;

template<typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


ii operator*(const ld &left, const ii &right) {
    return {left*right.first, left*right.second};
}

ii operator+(const ii &left, const ii &right) {
    return {left.first+right.first, left.second+right.second};
}

int dl, dw, g, l;
bool vis[105];
ii dp[105];

ii f(int p) {
    if (p >= 100) p = 100;
    if (vis[p]) return dp[p];
    vis[p] = 1;
    
    ld lPer = (ld)l/100;
    ld gPer = (ld)g/100;
    ld pPer = (ld)p/100;

    ii intercept = {(1-lPer)*pPer*(1-gPer), 1};
    if (p == 100) return dp[p] = 1/(1-lPer)*intercept;
    return dp[p] = intercept + lPer*f(p+dl) + (1-lPer)*(1-pPer)*f(p+dw);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> dl >> dw >> g >> l;
    ii ans = f(0);

    cout << fixed << setprecision(10);
    cout << ans.second/(1-ans.first) << endl;

    return 0;
}