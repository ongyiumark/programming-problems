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

const int SQN = 708;
const int N = 5e5+5;
int c[N];

struct query {
  int l, r, i;
};

int colors[N];
int ans[N];

query queries[N];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, q; cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    c[i]--;
  }

  for (int i = 0; i < q; i++) {
    int l, r; cin >> l >> r;
    l--; r--;
    queries[i] = {l, r, i};
  }
  sort(queries, queries+q, [](const query &left, const query &right) {
    if (left.l/SQN == right.l/SQN) return left.r < right.r;
    return left.l/SQN < right.l/SQN;
  });

  memset(colors, 0, sizeof colors);
  int currL = 0;
  int currR = 0;
  int curr_ans = 1;
  colors[c[0]] = 1;

  for (int i = 0; i < q; i++) {
    int l = queries[i].l;
    int r = queries[i].r;
    while(currL < l) {
      colors[c[currL]]--;
      if (colors[c[currL]] == 0) curr_ans--;
      currL++;
    }
    while(currL > l) {
      currL--;
      colors[c[currL]]++;
      if (colors[c[currL]] == 1) curr_ans++;
    }

    while(currR < r) {
      currR++;
      colors[c[currR]]++;
      if (colors[c[currR]] == 1) curr_ans++;
    }
    while(currR > r) {
      colors[c[currR]]--;
      if (colors[c[currR]] == 0) curr_ans--;
      currR--;
    }

    ans[queries[i].i] = curr_ans;
  }

  for (int i = 0; i < q; i++) {
    cout << ans[i] << "\n";
  }
  return 0;

}
