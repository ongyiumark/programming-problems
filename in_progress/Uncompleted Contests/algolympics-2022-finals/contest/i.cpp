#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>,
    rb_tree_tag, tree_order_statistics_node_update>;
 
using ll = long long;
using ii = pair<ll, int>;
using vi = vector<int>;

multiset<ii> bridge; 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
 
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        string s; cin >> s;
        int x, y; cin >> x >> y;
        if (s == "ADD") {
            bridge.insert({y,x});
        }
        else if (s == "REM"){
            bridge.erase(bridge.find({y,x}));
        }
        else{
            int tmp = x;
            int cnt = 0;
            for (auto p : bridge){
                int col = p.second;
                int row = p.first;
                if (row > y) break;
                bool moved = false;
                //cout << "b: " << tmp << " " << col << endl;
                if (tmp == col) {
                    tmp = tmp+1;
                    moved = true;
                }
                else if (tmp-1 == col) {
                    tmp = tmp-1;
                    moved = true;
                }
                if (moved) cnt++;
                //cout << "a: " << tmp << " " << col << endl;
            }
            cout << tmp << " " << cnt << "\n";
        }
    }

    return 0;
}
