/*
  If the mountains are 2a, 2b, 2c, ...
  Then, the dams are a+b, b+c, c+d, ...
  We can solve for a+b+c+... by adding all A[i]'s and dividing by 2.
  We can then solve for a by subtracting b+c, c+d, ... This works because N is odd.
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
  for (int i = 0; i < n; i++) cin >> A[i];

  ll curr = 0;
  for (int i = 0; i < n; i++) curr += A[i];
  curr /= 2;

  for (int i = 1; i < n; i+=2) curr -= A[i];
  vector<ll> ans;
  for (int i = 0; i < n; i++) {
    ans.push_back(curr*2);
    curr = A[i] - curr;
  }

  for (ll x : ans) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
