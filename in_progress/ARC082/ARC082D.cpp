/*
  Swapping once is sufficient for each arranged index.
  We can minimize by greedily swapping forward since we have a change to derange the one in front.
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
int p[N];
int n;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i];

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += (i+1 == p[i]);
    if (i < n && i+1 == p[i]) swap(p[i], p[i+1]);
  }

  cout << cnt << endl;
  return 0;
}
