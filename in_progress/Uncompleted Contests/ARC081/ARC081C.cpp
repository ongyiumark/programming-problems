/*
  Sort and look for the highest numbers with a pair.
  Be careful of overflow.
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
ll A[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n; cin >> n;
  for (int i = 0 ; i < n; i++) cin >> A[i];
  sort(A, A+n, greater<ll>());

  vector<ll> dubs;
  for (int i = 1; i < n; i++) {
    if (A[i] == A[i-1]) {
      dubs.push_back(A[i]);
      i++;
    }
  }
  if (dubs.size() <= 1) cout << 0 << endl;
  else cout << dubs[0]*dubs[1] << endl;
  return 0;
}
