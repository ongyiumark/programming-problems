/*
  The only way to get a multiple of 4 is two 2 (mod 4)s or a 0 (mod 4).
  So we need to have enough 0 (mod 4)s to fill in the spaces between the others,
    counting the 2 (mod 4)s as a single entity.
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

const int N = 1e5+5;
int a[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;

  int cnt[4];
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    a[i] = x%4;
    cnt[a[i]]++;
  }

  int other = (cnt[2] > 0 ? 1 : 0) + cnt[1] + cnt[3];
  cout << (cnt[0] >= other-1 ? "Yes" : "No") << endl;
  
  return 0;
}
