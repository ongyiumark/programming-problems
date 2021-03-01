/*
  Partition the sequence in to alternating sequences.
  Suppose that A B C D ... are partitions. If we flip B, say B', A B' C becomes an alternating sequence.
  If we know the length of each partition, we can compute for the
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

const int N = 1e5;
bool bulb[N];
int cnt[N];
int nxt[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> bulb[i];
  
  cnt[n-1] = 1;
  nxt[n-1] = n;
  for (int i = n-2; i >= 0; i--){
    if (bulb[i] != bulb[i+1]) {
      cnt[i] = cnt[i+1]+1;
      nxt[i] = nxt[i+1];
    }
    else {
      cnt[i] = 1;
      nxt[i] = i+1;
    }
  }

  int ans = cnt[0];
  for (int i = 0; nxt[i] < n; i = nxt[i]){
    int curr = cnt[i] + cnt[nxt[i]];
    if (nxt[nxt[i]] < n) curr += cnt[nxt[nxt[i]]];
    ans = max(curr, ans);
  }
  cout << ans << endl;
  return 0;
}
