/*
  Maintain a merge sort tree.
  Check if first element and last element in the a segment is x.
  Probably overkill, but its the first thing I thought of.
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

const int N = 2e5+5;
int a[N];
vector<pii> mergetree[4*N];

void generate(int l, int r, int p){
  if (l == r) {
    mergetree[p].push_back({a[l],l});
    return;
  }
  int k = (l+r)/2;
  generate(l, k, 2*p); generate(k+1, r, 2*p+1);
  vector<pii> &a = mergetree[2*p];
  vector<pii> &b = mergetree[2*p+1];

  int i = 0, j = 0;
  while (i < a.size() || j < b.size()){
    if (i == a.size()) {
      mergetree[p].push_back(b[j++]);
      continue;
    }
    if (j == b.size()){
      mergetree[p].push_back(a[i++]);
      continue;
    }

    if (a[i].first < b[j].first) mergetree[p].push_back(a[i++]);
    else mergetree[p].push_back(b[j++]);
  }
}

int query(int l, int r, int p, int i, int j, int x){
  int k = (l+r)/2;
  if (r < i) return -1;
  if (j < l) return -1;
  if (i <= l && r <= j){
    vector<pii> &tmp = mergetree[p];
    if (tmp.begin()->first != x) return tmp.begin()->second + 1;
    if ((--tmp.end())->first != x) return (--tmp.end())->second + 1;
    return -1;
  }

  return max(query(l, k, 2*p, i, j, x), query(k+1, r, 2*p+1, i, j, x));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  generate(0, n-1, 1);

  while(m--){
    int l, r, x; cin >> l >> r >> x;
    cout << query(0, n-1, 1, l-1, r-1, x) << endl;
  }
  return 0;
}
