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


const int MAXN = 3e5+5;
int a_pref[MAXN], b_pref[MAXN]; // 1-indexed

int main(){
  cin.tie(0)->sync_with_stdio(false);
  memset(a_pref, 0, sizeof a_pref);
  memset(b_pref, 0, sizeof b_pref);

  int n, a, b; cin >> n >> a >> b;
  string s; cin >> s;
  for (int i = 0; i < n; i++) {
    a_pref[i+1] = a_pref[i] + (s[i] == 'a');
    b_pref[i+1] = b_pref[i] + (s[i] == 'b');
  }

  ll result = 0;
  for (int r = 0; r < n; r++) {
    // binary search largest l for a
    int a_lo = 0;
    int a_hi = r;
    int a_ans = -1;
    while (a_lo <= a_hi) {
      int mid = a_hi - (a_hi-a_lo)/2;
      if (a_pref[r+1]-a_pref[mid] >= a) {
        a_ans = mid;
        a_lo = mid+1;
      }
      else {
        a_hi = mid-1;
      }
    }

    // binary search smallest l for b
    int b_lo = 0;
    int b_hi = r;
    int b_ans = -1;
    while (b_lo <= b_hi) {
      int mid = b_hi - (b_hi-b_lo)/2;
      if (b_pref[r+1]-b_pref[mid] < b) {
        b_ans = mid;
        b_hi = mid-1;
      }
      else {
        b_lo = mid+1;
      }
    }
    
    // possible l for a: 0...a_ans
    // possible l for b: b_ans...r
    if (a_ans != -1 && b_ans != -1 && b_ans <= a_ans) result += (a_ans-b_ans+1);
  }

  cout << result << endl;


  return 0;
}
