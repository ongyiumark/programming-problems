/*
  There are two cases:
    - a[i] = i and a[j] = j
    - a[i] = j and a[j] = i
  If a[i] = i, it can be paired with any 1 <= i < j <= n such that a[j] = j.
    We can count the number of pairs by counting how many 1 <= i <= n such that a[i] == i and choosing all pairs.
  If a[i] = j, then we simply need to check if a[j] = i.
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

const int N = 5e5+5;
vector<int> a(N);

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  ll correct = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == i) correct++;
  } 
  ll flip = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] != i && a[a[i]] == i) flip++;
  }

  cout << flip/2 + correct*(correct-1)/2 << endl;
  return 0;
}
