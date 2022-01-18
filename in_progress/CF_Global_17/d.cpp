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

const int N = 2e5+5;
const int MOD = 1e9+7;
int A[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    ll odd = 0, even = 0;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if (A[i] % 2 == 0) {
            odd = (odd*2)%MOD;
            even = (even*2+1)%MOD;
        }
        else {
            even = (even + odd)%MOD;
            odd = (odd + even + 1)%MOD;
        }
    } 

    for (int i = 0; i < n; i++) {
        
    }
    cout << odd << "\n";
    return 0;
}