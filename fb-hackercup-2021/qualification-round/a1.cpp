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

bool is_vowel(char c){
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

void testcase(){
    string s; cin >> s;
    int n = s.size();
    int best = 1e9;
    for (int i = 0; i < 26; i++){
        char ch = i+'A';
        int curr = 0;
        for (int j = 0; j < n; j++){
            if (s[j] == ch) continue;
            curr += 1 + (is_vowel(ch)==is_vowel(s[j]));
        }
        best = min(best, curr);
    }
    cout << best << endl;
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