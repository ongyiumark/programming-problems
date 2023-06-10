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

const int N = 3e5+5;
int a[N], b[N];
map<int, queue<int>> idx;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) idx[b[i]].push(i);

    vector<string> ans;
    int i = 0;
    while(i < n) {
        int j = idx[a[i]].front();
        idx[a[i]].pop();
        ans.push_back(to_string(b[i]));
        i++;
        while(i < n && idx[a[i]].front() < j) {
            idx[a[i]].pop();
            ans.push_back(to_string(b[i]));
            i++;
        }
        
        if (i == j+1) ans.push_back("#");
    }

    ans.pop_back();
    int m = ans.size();
    for (int i = 0; i < m; i++) {
        cout << ans[i];
        if (i < m-1) cout << " ";
        else cout << endl;
    }
    return 0;
}