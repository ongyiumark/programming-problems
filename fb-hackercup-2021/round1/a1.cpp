#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T,null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;

string s;
void testcase(){
    int n; cin >> n;
    cin >> s;
    
    int i = 0;
    int cnt = 0;
    while(i < n && s[i] == 'F') i++;
    if (i == n) {
        cout << cnt << endl;
        return;
    }

    bool is_left = (s[i]=='X');
    while(i < n){
        if (is_left){
            while(i < n && s[i] != 'O') {
                i++;
            }
        }
        else {
            while(i < n && s[i] != 'X') {
                i++;
            }
        }
        is_left = !is_left;
        cnt++;
    }
    cout << cnt-1 << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int x = 1; x <= t; x++){
        cout << "Case #" << x << ": ";
        testcase();
    }
    return 0;
}