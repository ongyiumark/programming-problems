/*
  Go through each element one by one. Maintain a dictionary of frequency of "complements."
  Add the number of times that complement is needed when it appears.
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
ll a[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll pow2[32];
  pow2[0] = 1;
  for (int i = 1; i < 32; i++) pow2[i] = 2*pow2[i-1];

  ll cnt = 0;
  for (int k = 0; k < 32; k++) {
    map<ll,int> want;
    for (int i = 0; i < n; i++) {
      if (a[i] >= pow2[k]) continue;
      cnt += want[a[i]];
      want[pow2[k]-a[i]]++;
    }
  }
  cout << cnt << endl;
  
  return 0;
}
