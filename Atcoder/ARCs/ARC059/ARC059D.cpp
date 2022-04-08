/*
    Observe that if two of the same letter are next to each other or one apart,
        that substring is unbalance.
    If the next letter that is the same is more than 1 letter apart,
        there's no substring that is unbalanced.
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pair<int,int>> piii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

string s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> s;
    int n = s.size();

    for (int i = 0; i < n-1; i++){
        if (s[i] == s[i+1]){
            cout << i+1 << " " << i+2 << endl;
            return 0;
        }
        if (i+2 < n && s[i] == s[i+2]){
            cout << i+1 << " " << i+3 << endl;
            return 0;
        }
    }
    cout << -1 << " " << -1 << endl;
    return 0;
}