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

vector<ll> p;
const int N = 1e7+5;
bitset<N> isc;
vector<int> is_even(N);

void sieve() {
  for (int i = 2; i < N; i++) {
    if (!isc[i]) {
      p.push_back(i);
      is_even[i] = -1;
    }
    for (int j = 0; j < p.size() && i*p[j] < N; j++) {
      isc[i*p[j]] = 1;
      if (i % p[j] != 0) { 
        is_even[i*p[j]] = is_even[i]*is_even[p[j]];
      }
      else {
        is_even[i*p[j]] = is_even[i];
        break;
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve();
  vector<int> pref(N);
  pref[1] = 0;
  for (int i = 2; i < N; i++) {
    pref[i] = pref[i-1] + is_even[i];
  }

  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r; cin >> l >> r;
    cout << pref[r] - pref[l-1] << "\n";
  }
  
  return 0;
}
