/*
    We can simply add and remove using ordered multisets.
    Another way would be to use priority queues.
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

template <typename T>
using ordered_multiset = __gnu_pbds::tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5;
int x[N];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];

    ordered_multiset<int> nums;
    for (int i = 0; i < n; i++) nums.insert(x[i]);

    for (int i = 0; i < n; i++){
        if (i > 0) nums.insert(x[i-1]);
        nums.erase(nums.find_by_order(nums.order_of_key(x[i])));
        cout << *nums.find_by_order(n/2-1) << endl;
    }
    return 0;
}