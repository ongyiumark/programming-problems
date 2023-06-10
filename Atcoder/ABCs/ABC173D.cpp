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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  vector<ll> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];

  sort(A.begin(), A.end());

  ll total = A[n-1];
  int num = n-2;
  for (int i = n-2; i >= 0 && num > 0; i--) {
    if (num > 1) {
      num -= 2;
      total += 2*A[i];
    }
    else {
      num -= 1;
      total += A[i];
    }
  }

  cout << total << "\n";
  return 0;
}
