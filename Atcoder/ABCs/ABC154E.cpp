#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,pair<int,int>> iii;

template <typename T>
using ordered_set = __gnu_pbds::tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

string s;
int k;
int n;

ll memo[105][2][2][5];

ll solve(int i, bool is_below, bool has_started, int kk) {
    ll &ans = memo[i][is_below][has_started][kk];
    if (ans != -1) return ans;
    if (kk > k) return ans = 0;
    if (i == n) return ans = (k == kk);

    ans = 0;
    if (has_started && is_below) {
        for (int j = 0; j <= 9; j++) {
            ans += solve(i+1, true, true, kk + (j != 0));
        }
    }
    else if (has_started) {
        for (int j = 0; j <= s[i]-'0'; j++) {
            ans += solve(i+1, (j < s[i]-'0'), true, kk + (j != 0));
        }
    }
    else if (is_below) {
        for (int j = 0; j <= 9; j++) {
            ans += solve(i+1, true, (j != 0), kk + (j != 0));
        }
    }
    else {
        ans += solve(i+1, true, false, kk);
        for (int j = 1; j <= s[i]-'0'; j++) {
            ans += solve(i+1, (j < s[i]-'0'), true, kk + (j != 0));
        }
    }
    return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s >> k;
  n = s.size();

  memset(memo, -1, sizeof memo);
  cout << solve(0, 0, 0, 0) << "\n";
  
  return 0;
}
