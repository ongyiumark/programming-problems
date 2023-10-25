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
  vector<ll> s(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  sort(s.rbegin(), s.rend());
  if (n == 1) {
    cout << 1 << "\n";
    return 0;
  }

  ll ans_total = s[0];
  ll current_total = 0;
  int i = 1;
  int result = 1;
  while (i < n) {
    current_total += s[i];
    if (current_total >= ans_total) {
      ans_total += current_total;
      current_total = 0;
      result = i+1;
    }
    i++;
  }
  cout << result << "\n";
  return 0;
}
