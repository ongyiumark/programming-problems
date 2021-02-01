/*
  Count the number of unique integers.
  If its more than k, change the integers with the least counts.
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

const int N = 2e5+1;
int counts[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;
  cin >> n >> k;
  set<int> diff;
  memset(counts, 0, sizeof counts);
  for (int i = 0; i < n; i++){
    int a; cin >> a;
    counts[a]++;
    diff.insert(a);
  }
  
  if (diff.size() <= k){
    cout << 0 << endl;
    return 0;
  }

  vector<pii> rcnt;
  for (int i = 0; i < N; i++){
    if (counts[i] == 0) continue;
    rcnt.push_back({counts[i], i});
  }
  sort(rcnt.begin(), rcnt.end());

  int ans = 0;
  for (int i = 0; i < (int)diff.size()-k; i++){
    ans += rcnt[i].first;
  }
  cout << ans << endl;
  return 0;
}
