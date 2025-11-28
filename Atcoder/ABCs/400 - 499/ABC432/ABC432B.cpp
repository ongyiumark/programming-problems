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
  cin.tie(0)->sync_with_stdio(false);
  string s; cin >> s;
  int n = s.size();
  vector<char> ss(n);

  int j = 0;
  int smallest = 10;
  for (int i = 0; i < n; i++) {
    ss[i] = s[i];
    int dig = s[i]-'0';
    if (dig > 0 && dig < smallest) {
      smallest = dig;
      j = i;
    }
  }

  swap(ss[0], ss[j]);
  sort(ss.begin()+1, ss.end());
  for (int i = 0; i < n; i++) cout << ss[i];
  cout << "\n";
  return 0;
}
