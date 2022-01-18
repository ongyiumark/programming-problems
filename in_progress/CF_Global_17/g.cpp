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

const int N = 3e5+5;
int cnt[N];
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int a, b;
    a = b = -1;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            a = i;
            break;
        }
    }

    for (int i = a; i < n; i++) {
        if (s[i] == ')') {
            if (i+1 < n && s[i+1] == '('){
                b = i;
                break;
            }
            else b = i;
        }
    }


    for (int i = 0; i < n; i++) {
        if (i == a || i == b) continue;
        cout << s[i];
    }
    cout << "\n";
    return 0;
}