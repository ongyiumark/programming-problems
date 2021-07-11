/*
    Notice that n+1 choose k >= n choose r for any valid r and k, so it's optimal to choose the largest number for n.
    Then, simply binary search or sweep for the closest number to half.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5;
int a[N];
int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);

    int lo = 0;
    int hi = n-2;
    int ans = -1;
    while(lo <= hi){
        int mid = hi - (hi-lo)/2;
        if (a[n-1] >= 2*a[mid]){
            ans = mid;
            lo = mid+1;
        }
        else hi = mid-1;
    }
    if (ans == -1) cout << a[n-1] << " " << a[0] << endl;
    else if (ans+1 < n-1){
        if (a[ans]+a[ans+1] > a[n-1]) cout << a[n-1] << " " << a[ans] << endl;
        else cout << a[n-1] << " " << a[ans+1] << endl;
    }
    else cout << a[n-1] << " " << a[ans] << endl;
    return 0;
}