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
int A[N], B[N];

bool valid (int x, int n) {
    int cnt = 0;
    int a = x-1;
    int b = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] >= a && B[i] >= b) {
            a--;
            b++;
        }
        if (a < 0) return true;
    }
    return false;
}

void testcase(){
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i] >> B[i];
    
    int lo = 0;
    int hi = n;
    int ans = -1;
    while(lo <= hi) {
        int mid = hi - (hi-lo)/2;
        if (valid(mid, n)) {
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int i = 0; i < t; i++){
        testcase();
    }
    return 0;
}