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
int A[N];

bool is_palindrome(vi& arr){
    int n = arr.size();
    for (int i = 0; i < n; i++){
        if (arr[i] != arr[n-1-i]) return false;
    }
    return true;
}

void testcase() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    int l, r;
    l = 0; r = n-1;
    while(l <= r && A[l] == A[r]){
        l++;
        r--;
    }
    if (l > r) {
        cout << "YES\n";
        return;
    }

    int t1 = A[l];
    int t2 = A[r];

    vector<int> tmp1;
    vector<int> tmp2;
    for (int i = 0; i < n; i++) {
        if (A[i] != t1) tmp1.push_back(A[i]);
        if (A[i] != t2) tmp2.push_back(A[i]);
    }

    if (is_palindrome(tmp1) || is_palindrome(tmp2)) {
        cout << "YES\n";
    }
    else cout << "NO\n";
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